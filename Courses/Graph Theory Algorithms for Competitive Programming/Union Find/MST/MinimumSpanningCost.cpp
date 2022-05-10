#include<bits/stdc++.h>
using namespace std;

// simple union find class
class UF {
public:
vector<int> sets, cards;
int components;
UF(int n) {
    components = n;
    sets = cards = vector<int>(n,0);
    for (int x = 0; x < n; ++x)
        sets[x] = x, cards[x] = 1;
};

int find(int u) { return u == sets[u] ? u : ( sets[u] = find(sets[u])); };

int uni(int u, int v) {
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

    components--;
    return true;
};

};

/*

Approach: Classic Kruskal's.

*/

// special sort comparator for Kruskal's
bool comp(vector<int> edgeA, vector<int> edgeB) {
    return edgeB[2] > edgeA[2];
};

// classic Kruskal's implementation.
int MST(int n, vector<vector<int>> edges) {
    UF dj = UF(n+1);
    int mstcost = 0;
    sort(edges.begin(), edges.end(), comp);

    int mstEdgeCount = 0;
    for (auto e: edges) {
        if (dj.uni(e[0], e[1])) {
            mstcost += e[2];
            mstEdgeCount++;
            if (mstEdgeCount == n-1) break;
        };
    };

    return mstcost;
}