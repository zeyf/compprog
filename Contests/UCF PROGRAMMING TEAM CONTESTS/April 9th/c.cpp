#include <bits/stdc++.h>
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

int main () {

    map<int, set<pair<int, int> > > graph;
    map<int, multiset<int> > vertexMinEdgeWeights;
    int n, k; cin >> n >> k;

    int x;
    range(0, n-1, 1, x) {
        int u, v, w; cin >> u >> v >> w;
        if (!graph.count(u)) {
            graph[u] = set<pair<int, int> >();
            vertexMinEdgeWeights[u] = multiset<int>();
        };

        if (!graph.count(v)) {
            graph[v] = set<pair<int, int> >();
            vertexMinEdgeWeights[v] = multiset<int>();
        };

        graph[u].insert(make_pair(w, v));
        vertexMinEdgeWeights[u].insert(w);
        graph[v].insert(make_pair(w, u));
        vertexMinEdgeWeights[v].insert(w);
    };

    set<int> candidateSites;
    range(0, k, 1, x) {
        int aptComplex; cin >> aptComplex;
        candidateSites.insert(aptComplex);
        pair<int, int> minDistEdge = *(graph[aptComplex].lower_bound(make_pair(0,0)));
        if (vertexMinEdgeWeights[aptComplex].count(minDistEdge.first) == 1)
            candidateSites.insert(minDistEdge.second); 
    };

    cout << candidateSites.size() << "\n";

    return 0;
};