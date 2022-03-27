#include <bits/stdc++.h>

/*

Idea:

Create an efficient union find/disjoint set data structure.

How will this be done?

- Path compression
- Union by Rank (size)

*/
class UnionFind {
	public:
		UnionFind(unsigned int size) { init(size); };

		int find(int u) {
			if (u == sets[u]) return u;
			return (sets[u] = find(sets[u]));
		};

		bool uni(int u, int v) {
			int uSet = find(u), vSet = find(v);
			if (uSet == vSet) return false;
			
			if (cards[uSet] > cards[vSet]) {
				cards[uSet] += cards[vSet];
				cards[vSet] = 0;
				sets[vSet] = uSet;
			} else {
				cards[vSet] += cards[uSet];
				cards[uSet] = 0;
				sets[uSet] = vSet;
			};

			numComponents--;
			return true;
		};
		
		bool sameSet(int u, int v) {
			return find(u) == find(v);
		};

		unsigned int getSetsCount() { return numComponents; };
		int getSetSize(int u) { return cards[find(u)]; };

	private:
		unsigned int n, numComponents;
		// sets with respective cardinalities
		vector<int> sets, cards;
		void init(unsigned int size) {
			n = numComponents = size;
			sets = vector<int>(size);
			cards = vector<int>(size);
			for (int x=0;x<n;x++) {
				sets[x] = x;
				cards[x] = 1;
			};
		};
		
		int findIt(int u) {
			int root = u, c = u;
			while (root != sets[root])
				root = sets[root];

			// path compression
			while (c != root) {
				int p = sets[c];
				sets[c] = root;
				c = p;
			};

			return root;
		};

};