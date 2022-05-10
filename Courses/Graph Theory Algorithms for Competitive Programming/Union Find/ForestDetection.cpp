#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*DEFINES*/

#define add push_back
#define rem pop_back
#define ins insert
#define co count
#define fi first
#define se second
#define sorter(a, comp) sort(a.begin(), a.end(), comp)
#define sz(a) a.size()
#define nl << "\n"
#define cnl cout << "\n"


/*
TYPEDEFS
*/

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pllll;

/*
SET TYPEDEFS
*/

typedef set<int> si;
typedef set<ll> sll;
typedef set<string> ss;
typedef set<pii > spii;
typedef set<pllll > spllll;

/*
VECTOR TYPEDEFS
*/

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pii > vpii;
typedef vector<char> vc;
typedef vector<vc > vvc;
typedef vector<vi > vvi;

/*
MAP TYPEDEFS
*/

typedef map<int, int> mii;
typedef map<ll, ll> mllll;
typedef map<string, int> msi;
typedef map<char, int> mci;
typedef map<int, vi > mivi;
typedef map<string, vs > msvs;

// simple union find class.
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

Approach: Simple Union Find for cycle detection.

*/

bool solve(vector<vector<int>> edges) {
	// init union find
	UF dj = UF(1000000);

	// any tree or forest (collection of trees) will not have a cycle.
	// if a union fails, it means we would have created a cycle if so. therefore we do not only have trees.
	for (auto e: edges)
		if (!dj.uni(e[0], e[1]))
			return false;
	
	// we have a forest
	return true;
}

/*


Graph Theory Algorithms for Competitive Programming (2022)
Forest Detection
You are given a list of lists edges representing an undirected graph. Each list contains (u, v) which means there is an undirected edge between nodes u and v. Return whether the graph is a collection of trees.

Constraints

n ≤ 100,000 where n is the length of edges

0 <= u, v <=100,000

*/