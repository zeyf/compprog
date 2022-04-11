#include <bits/stdc++.h>
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;


void shortestpath(int start, int V, map<int, vector<pair<int, int> > > &adj) {
    const int MAXIMAL = 10e9;
    vector<int> parents = vector<int>(V);
    vector<int> distances = vector<int>(V, 10e9);
    int x;
    range(0, adj.size(), 1, x) parents[x] = x;
    distances[start] = 0;
    set<pair<int, int>> q;
    q.insert({0, start});


    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (distances[v] + len < distances[to]) {
                q.erase({distances[to], to});
                distances[to] = distances[v] + len;
                parents[to] = v;
                q.insert({distances[to], to});
            }
        }
    }
}


int main () {




    return 0;
}