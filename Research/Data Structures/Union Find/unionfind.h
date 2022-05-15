#include <bits/stdc++.h>
using namespace std;

class UnionFind {
	public:
		UnionFind(unsigned int size) {
			n = numComponents = size;
			sets = vector<int>(size);
			cards = vector<int>(size);
			for (int x = 0; x < n; x++) {
				sets[x] = x;
				cards[x] = 1;
			};
		};

		// Finds the root node of a given set.
		// The base case is when the current set index is equal to what is at that index (the root was found).
		// This also performs path compression on every node when descending down from the recursive calls by assigning each node to point to the root, until the initial node.
		int find(int u) {
			if (u == sets[u]) return u;
			return (sets[u] = find(sets[u]));
		};

		// Unions disjoint sets together. Indirectly performs path compression via find calls to both u and v, regardless if no union will occur.
		bool uni(int u, int v) {
			int uSet = find(u), vSet = find(v);
			
			// If both u and v belong to the same set (same root), return false.
			//  We can not union these two nodes without a cycle being formed. They belong to the same connected component.
			if (uSet == vSet) return false;

			// If the uSet has a greater cardinality than the vSet, union vSet into uSet
			if (cards[uSet] > cards[vSet]) {
				cards[uSet] += cards[vSet];
				cards[vSet] = 0;
				sets[vSet] = uSet;
			// If the vSet has a greater or equal cardinality than the uSet, union uSet into vSet
			} else {
				cards[vSet] += cards[uSet];
				cards[uSet] = 0;
				sets[uSet] = vSet;
			};

			// At this point, a union of two disjoint was made, and the number of connected components has dropped by one.
			// Return true, this signifies a successful merge.
			numComponents--;
			return true;
		};
		
		// Returns if u and v are part of the same set. Also indirectly path compresses node u to it's root, and node v to it's root.
		bool sameSet(int u, int v) {
			return find(u) == find(v);
		};

		// Returns the number of connected components / disjoint sets.
		unsigned int getSetsCount() { return numComponents; };

		// Returns the cardinality of a given disjoint set / connected component.
		int getSetSize(int u) { return cards[find(u)]; };

	private:
		unsigned int n, numComponents;
		vector<int> sets, cards;
		
		// Iterative approach to the find function. Much less elegant than the recursive approach.
		int findIt(int u) {
			// Start two "pointers" at the node in question.
			int root = u, c = u;

			// Iterate the "root" pointer, until it lands at the ACTUAL root -- it's value matches the value at the index.
			// This means the root of the disjoint set was found.
			while (root != sets[root])
				root = sets[root];

			// Iterate another pointer now that you know the root of the disjoint set.
			// Path compress every node to point to the root instead, until you get to the root or a node already pointing to the root.
			while (c != root) {
				int p = sets[c];
				sets[c] = root;
				c = p;
			};

			// Return the root of the disjoint set which u belongs to.
			return root;
		};

};