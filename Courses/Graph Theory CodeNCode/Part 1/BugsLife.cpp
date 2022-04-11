#include <bits/stdc++.h>
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

#define UNVISITED (int)10e8

/*

https://www.spoj.com/problems/BUGLIFE/

Utilized bipartiteness checking to verify that there is no "bad" interactions between bugs...
Did this for all possible connected components of a given test case.

Note to self... stop using int. and dont use an int 10e9... lol. spent like 2 hours trying to get past that until i realized it was overflow.

*/

bool bipartite(int c, map<int, vector<int> > &graph, vector<int> &colors, int color) {
    colors[c] = color;

    int x;
    range(0, graph[c].size(), 1, x) {
        int nbr = graph[c][x];
        if (colors[nbr] == UNVISITED) {
            if (!bipartite(nbr, graph, colors, !color))
                return false;
        } else if (colors[nbr] == color) {
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
        vector<int> colors(n+1, UNVISITED);

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
            if (colors[x] == UNVISITED && !bipartite(x, graph, colors, 0))
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