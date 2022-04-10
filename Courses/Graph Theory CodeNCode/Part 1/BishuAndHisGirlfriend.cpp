#include <bits/stdc++.h>
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

#define UNVISITED (int)10e9

/*

https://assessment.hackerearth.com/challenges/college/nits-local-10/algorithm/84888e824aa04fc793c3beefca02b5a7/

Used DFS to calculate distances and then used the populated distance table to find the girlfriend.

*/

void f(int c, map<int, vector<int> > &graph, vector<int> &dist) {

    int x;
    range (0, graph[c].size(), 1, x) {
        int nbr = graph[c][x];
        if (dist[nbr] == UNVISITED) {
            dist[nbr] = dist[c]+1;
            f(nbr, graph, dist);
        };
    };

};

int main () {

    int n; cin >> n;
    int x;

    vector<int> dist(n+1, UNVISITED);

    map<int, vector<int> > graph;
    range(0, n-1, 1, x) {
        int u, v; cin >> u >> v;
        if (!graph.count(u))
            graph[u] = vector<int>();
        if (!graph.count(v))
            graph[v] = vector<int>();
        graph[u].push_back(v);
        graph[v].push_back(u);
    };

    dist[1] = 0;
    f(1, graph, dist);

    int q; cin >> q;

    int minDistance = UNVISITED, minIdx = UNVISITED;
    while (q--) {
        int girlCountry; cin >> girlCountry;
        if (minDistance >= dist[girlCountry]) {
            minDistance = dist[girlCountry];
            if (minIdx > girlCountry)
                minIdx = girlCountry;
        };
    };

    cout << minIdx << "\n";

    return 0;
};