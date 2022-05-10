#include<bits/stdc++.h>
using namespace std;

typedef map<int, vector<int> > mivi;

void dfs(int u, int p, mivi &graph, vector<int> &lowlink, vector<int> &intime, set<int> &visited, vector<vector<int> > &critical, int timer = 1) {
    
    visited.insert(u);
    intime[u] = lowlink[u] = timer;

    for (auto v: graph[u]) {
        if (v==p) continue;
        if (!visited.count(v)) {
            dfs(v, u, graph, lowlink, intime, visited, critical, timer+1);
            lowlink[u] = min(lowlink[u], lowlink[v]);
            if (lowlink[v] > intime[u]) {
                vector<int> edge = { u, v };
                critical.push_back(edge);
            }
        } else {
            lowlink[u] = min(lowlink[u], intime[v]);
        }
    }
};

vector<vector<int>> criticalConnections(int n, vector<vector<int>> connections) {

    vector<int> lowlink(1000000, 0), intime(1000000, 0);
    vector<vector<int> > critical;
    set<int> visited;
    mivi graph;
    for (auto e: connections)
        graph[e[0]].push_back(e[1]), graph[e[1]].push_back(e[0]);
    
    for (int u = 0; u < n; ++u)
        if (!visited.count(u))
            dfs(u, u, graph, lowlink, intime, visited, critical);
    return critical;
}

/*

Graph Theory Algorithms for Competitive Programming (2022)
Fault in a Network
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

Constraints:

2 <= n <= 10^5

n - 1 <= connections.length <= 10^5

0 <= ai, bi <= n - 1

ai != bi

There are no repeated connections.



Example:



Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.


Expected Time Complexity: O(n+m), where m is connections.length

*/