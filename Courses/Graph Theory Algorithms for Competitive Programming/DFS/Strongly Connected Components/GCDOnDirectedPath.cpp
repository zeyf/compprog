#include<bits/stdc++.h>
using namespace std;

/*

Approach: Create an adjacency list of edges with weights. These weights will be the the gcd of the cost between a u and v

*/

int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); };

ll dfs(int u, map<int, vector<pair<int, int> > > &graph,  set<int> &visited) {
    visited.insert(u);



    visited.erase(u);
    return ans;
};


int solve(int n,vector<int> c, vector<vector<int>> edges){
    map<int, vector<pair<int, int> > > graph;
    for (auto e: edges)
        graph[e[0]].push_back(make_pair(gcd(c[e[0]-1], c[e[1]-1]), e[1]));

    ll ans = 10e16;
    for (int u = 1; u < n; ++u)
        ans = min(ans, dfs(u, graph, visited));

    cout << ans << "\n";
    return ans;
}
