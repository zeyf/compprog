#include<bits/stdc++.h>
using namespace std;

// simple union find class
class UF {
public:
vector<int> sets, cards;
int components;
UF(int n) {
	components = n;
	sets = cards = vector<int>(components);
	for (int x = 0; x < components; ++x)
		sets[x] = x, cards[x] = 1;
}

int find(int u) { return u == sets[u] ? u : (sets[u] = find(sets[u])); };

bool uni(int u, int v) {
	int uset = find(u), vset = find(v);
	if (uset == vset) return false;

	if (cards[uset] > cards[vset]) {
		cards[uset] += cards[vset];
		cards[vset] = 0;
		sets[vset] = uset;
	} else {
		cards[vset] += cards[uset];
		cards[uset] = 0;
		sets[uset] = vset;
	};

	components--;
	return true;
}

};

/*

Approach:
- Map each point to an index in the Disjoint Set via map<pair<long long, long long>, long long>
- Find all pairs of points and their respective weights.
- Sort these edges in ascending order of weight.
- Perform Kruskal's with Disjoint Set by unmapping the points into indexes for Union...

*/

// disgusting custom sort comparator
bool comp(pair<long long, pair<pair<long long, long long>, pair<long long, long long> > > a, pair<long long, pair<pair<long long, long long>, pair<long long, long long> > > b) {
	return b.first > a.first;
}


int minCostConnectPoints(vector<vector<int>> points) {

	// initialize edges and pointMap for point to index mapping for union find...
	vector<pair<long long, pair<pair<long long, long long>, pair<long long, long long> > > > edges;
	map<pair<long long, long long>, long long > pointMap;
	int i = 0;
	for (auto e: points) {
		pointMap[make_pair((long long)e[0], (long long)e[1])] = i++;
	};

	// create the edges from pairs of points
	for (int u = 0; u < points.size(); ++u) {
		for (int v = u+1; v < points.size(); ++v) {
		    int pointUX = points[u][0], pointUY = points[u][1],
		        pointVX = points[v][0], pointVY = points[v][1];
		    pair<long long, long long> pointU = make_pair(pointUX,pointUY), pointV = make_pair(pointVX, pointVY);
		    edges.push_back(make_pair((long long)(abs(pointUX-pointVX)+abs(pointUY-pointVY)), make_pair(pointU, pointV)) );
		    
		};
	};

	// From here classic Kruskal's...

	sort(edges.begin(), edges.end(), comp);

	UF dj = UF(points.size());
	long long mstcost = 0;
	for (auto e: edges) {
		if (dj.uni(pointMap[e.second.first], pointMap[e.second.second]))
			mstcost += e.first;
	};

	return mstcost;
}

/*

Graph Theory Algorithms for Competitive Programming (2022)
Connect All
Given n  Points (xi,yi) where  0<=i<=n . Find the minimum Cost to connect all points.

Where cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.



Constraints :
n <= 10^3
-10^9 <= x,y <= 10^9
Input : Points : {{-1000000,-1000000},{1000000,1000000}}, n = 2
Output : 4000000


Expected time Complexity : O(n^2*log(n^2))

*/