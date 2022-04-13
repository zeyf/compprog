#include <bits/stdc++.h>
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

int main () {

    map<int, set<pair<int, int> > > graph;
    map<int, pair<int, int> > vertexMinEdgeWeights;
    int n, k; cin >> n >> k;

    int x;
    range(0, n-1, 1, x) {
        int u, v, w; cin >> u >> v >> w;
        if (!graph.count(u)) {
            graph[u] = set<pair<int, int> >();
            vertexMinEdgeWeights[u] = make_pair(w, 1);
        } else {
            if (vertexMinEdgeWeights[u].first > w)
                vertexMinEdgeWeights[u] = make_pair(w, 1);
            else if (vertexMinEdgeWeights[u].first == w)
                vertexMinEdgeWeights[u].second++;
        };
        if (!graph.count(v)) {
            graph[v] = set<pair<int, int> >();
            vertexMinEdgeWeights[v] = make_pair(w, 1);
        } else {
            if (vertexMinEdgeWeights[v].first > w)
                vertexMinEdgeWeights[v] = make_pair(w, 1);
            else if (vertexMinEdgeWeights[v].first == w)
                vertexMinEdgeWeights[v].second++;
        };

        graph[u].insert(make_pair(w, v));
        graph[v].insert(make_pair(w, u));
    };

    set<int> candidateSites;
    range(0, k, 1, x) {
        int aptComplex; cin >> aptComplex;
        candidateSites.insert(aptComplex);
        pair<int, int> minDistEdge = *(graph[aptComplex].lower_bound({0,0}));
        if (vertexMinEdgeWeights[aptComplex].second == 1)
            candidateSites.insert(minDistEdge.second);
    };



    cout << candidateSites.size() << "\n";

    return 0;
};