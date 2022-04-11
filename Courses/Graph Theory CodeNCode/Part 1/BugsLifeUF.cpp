#include <bits/stdc++.h>
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

#define UNVISITED (int)10e8

/*

https://www.spoj.com/problems/BUGLIFE/

Utilized bipartiteness checking to verify that there is no "bad" interactions between bugs...

Did it with a UnionFind/Disjoint Set! Was an interesting twist...

*/

class UnionFind {
	public:
		UnionFind(int n) {
            V = n;
			sets = vector<int>(n);
			cardinalities = vector<int>(n, 0);
			for (int x = 0; x < n; x++) sets[x] = x;
			setCount = n;
		};

		int find(int u) {
			if (u == sets[u]) return u;
			return (sets[u] = find(sets[u]));
		};
	
		bool uni(int u, int v) {
			int uSet = find(u), vSet = find(v);
			if (uSet == vSet) return false;
	
			int uSetSize = getSetSize(uSet), vSetSize = getSetSize(vSet);
			if (uSetSize > vSetSize) {
				cardinalities[uSet] += vSetSize;
				sets[vSet] = uSet;
			} else {
				cardinalities[vSet] += uSetSize;
				sets[uSet] = vSet;
			};
	
			setCount--;
			return true;
		};
	
		bool isSameSet(int u, int v) { return find(u) == find(v); };
		int getSetCount() { return setCount; };
		int getSetSize(int u) { return cardinalities[find(u)]; };
        int getElementCount() { return V; };
	
	private:
		vector<int> sets, cardinalities;
		int setCount, V;
};

bool bipartite(int c, map<int, vector<int> > &graph, UnionFind &uf, bool set) {
    // if the color is false, add to set A, else set B
    if (!set) uf.uni(c, 0);
    else uf.uni(c, uf.getElementCount()-1);

    int x;
    // go through the neighbors
    range(0, graph[c].size(), 1, x) {
        int nbr = graph[c][x];

        // finds the set of the neighbor
        int nbrSet = uf.find(nbr);

        // if the nbr == nbrSet, that means that nbr is unvisited as all nodes are either mapped to set A, set B, or neither.
        // Really, there are 3 sets in the universe -- initially A and B are both subsets of C, and C starts off == U, however
        // As we add elements to the A or B set, the size of C only decreases.
        // If unvisited, we need to add it to a set, therefore dfs to the nbr.
        if (nbr == nbrSet) {
            if (!bipartite(nbr, graph, uf, !set))
                return false;

        // if the current node (which is set to a given color) belongs to the same set as the neighbor, that means the graph is not bipartite.
        } else if (uf.isSameSet(c, nbr)) {
            return false;
        };
    };

    return true;
};

int main () {

    int t, tc; cin >> tc;
    range (1,tc+1,1,t) {
        cout << "Scenario #" << t << ":\n";
 
        map<int, vector<int> > graph;
        int n, e; cin >> n >> e;
        UnionFind uf = UnionFind(2005);

        while (e--) {
            int u, v; cin >> u >> v;
            if (!graph.count(u))
                graph[u] = vector<int>();
            if (!graph.count(v))
                graph[v] = vector<int>();
            graph[u].push_back(v);
            graph[v].push_back(u);
        };

        int x;
        bool good = true;
        range(1, n+1, 1, x) {

            // if the set of x is x, we have not visited x yet, so traverse.
            if (uf.find(x) == x && !bipartite(x, graph, uf, false))
                good = false;
            if (!good) break;
        };

        if (good)
            cout << "No suspicious bugs found!";
        else
            cout << "Suspicious bugs found!";

        cout << "\n";

    };

    return 0;
};