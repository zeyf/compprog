#include <bits/stdc++.h>
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*

https://www.spoj.com/problems/PT07Y/

Slapped a UnionFind/Disjoint Set like Kruskal on it.

*/

class UnionFind {
	public:
		UnionFind(int n) {
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
	
	private:
		vector<int> sets, cardinalities;
		int setCount;
};

int main () {

    int n, e; cin >> n >> e;
    if (e != n-1) {
        cout << "NO\n";
        return 0;
    };

    UnionFind uf = UnionFind(n);

    while (e--) {
        int u, v; cin >> u >> v;
        if(!uf.uni(u-1, v-1)) {
            cout << "NO\n";
            return 0;
        };
    };

    cout << "YES\n";

    return 0;
};