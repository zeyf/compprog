#include <bits/stdc++.h>
typedef long long ll;
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

#define UNVISITED (int)10e8



int main () {

    int tc; cin >> tc;
    while (tc--) {

        int n, e; cin >> n >> e;
        if (n==1) {
            cout << 0 << "\n";
            continue;
        }
        vector<ll> dist(n+1, UNVISITED);
        map<int, vector<int> > graph;
        while (e--) {
            int u, v; cin >> u >> v;
            if (!graph.count(u))
                graph[u] = vector<int>();
            if (!graph.count(v))
                graph[v] = vector<int>();
            graph[u].push_back(v);
            graph[v].push_back(u);
        };

        queue<int> q;
        q.push(1);
        dist[1] = 0;

        bool done = false;
        while (!q.empty() && !done) {
            int c = q.front(); q.pop();
            
            int x;
            range(0, graph[c].size(), 1, x) {
                int nbr = graph[c][x];
                if (dist[nbr] == UNVISITED) {
                    dist[nbr] = dist[c]+1;
                    q.push(nbr);
                    if (nbr == n) {
                        cout << dist[nbr] << "\n";
                        done = true;
                        break;
                    }
                };
            };
        };

    };

};