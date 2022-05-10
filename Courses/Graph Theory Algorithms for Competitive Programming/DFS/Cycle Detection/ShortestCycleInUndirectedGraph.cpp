#include<bits/stdc++.h>
using namespace std;

int dfs(int u, int p, map<int, vector<int> > &graph, unordered_set<int> &visited, vector<int> &intime, int timer = 1) {

    visited.insert(u);
    intime[u] = timer;
    int minCycle = 10e5;

    for (auto v: graph[u]) {
        if (v == p) continue;
        if (!visited.count(v))
            minCycle = min(minCycle, dfs(v, u, graph, visited, intime, timer + 1));
        else
            minCycle = min(minCycle, abs(intime[v]-intime[u])+1);
    };

    visited.erase(u);
    return minCycle;
};

int solve(int n,vector<vector<int>> edges){
    map<int, vector<int>> graph;
    unordered_set<int> visited;
    vector<int> intime(1000, 0);
    for (auto e: edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    };
    
    int ans = 10e5;
    for (int u = 0; u < n; ++u) {
        if (!visited.count(u))
            ans = min(ans, dfs(u, u, graph, visited, intime));
    }

    if (ans == (int)10e5) return -1;
    return ans;
}