#include<bits/stdc++.h>
using namespace std;

typedef map<int, vector<int> > mivi;

/*

Approach: Classic Tarjan's Articulation Points Algorithm use case

*/

void dfs(int u, int p, mivi &graph, set<int> &visited, vector<int> &intime, vector<int> &lowlink, set<int> &art, int timer = 0) {
    visited.insert(u);
    lowlink[u] = intime[u] = timer;
    int children = 0;
    for (auto v: graph[u]) {
        if (v==p) continue;
        if (!visited.count(v)) {
            dfs(v, u, graph, visited, intime, lowlink, art, timer + 1);
            lowlink[u] = min(lowlink[u], lowlink[v]);
            if (lowlink[v] >= intime[u] && u != p)
                art.insert(u);
            children++;
        } else {
            lowlink[u] = min(lowlink[u], intime[v]);
        };
    };

    if (u==p && children > 1)
        art.insert(u);
};


vector<bool> destructiveBob(int n, vector<vector<int>> edges, vector<int>queries)
{
    mivi graph;
    for (auto e: edges)
        graph[e[0]].push_back(e[1]), graph[e[1]].push_back(e[0]);
    set<int> visited, art;
    vector<int> lowlink(n+1, 0), intime(n+1,0);
    for (int u = 0; u < n; ++u) {
        if (!visited.count(u))
            dfs(u, u, graph, visited, intime, lowlink, art);
    };

    vector<bool> ans;
    for (auto q: queries) {
        ans.push_back(art.count(q) != 0);
    };
    
    return ans;
}

/*


Graph Theory Algorithms for Competitive Programming (2022)
Bob and Destructive Mind
Bob has  a graph with n nodes numbered 1 to n .

The graph is given as an array of edges where edges[i] = [ui, vi] is a bidirectional edge between node ui and vi, and also you are given an array of queries where queries[i]= x , so  bob will delete the node x and all the edges associated with it from the graph, if the number of connected components in the graph increase after the deletion of the node then bob will be satisfied. You have to find whether bob is satisfied after performing a query or not, return true if he is satisfied otherwise false.

Return an array containing answer for each query respectively.

Constraints:

2≤ n ≤ 10^5

1<= edges.length <= min(10^5, n*(n-1)/2)

1≤ queries.length ≤ 10^5

1<= ui, vi, x <=n



Example:

Input: n = 5, edges = [[1,2],[2,3],[3,4],[4,5],[3,5]],  queries= [1 ,2 ,3, 4, 5]
 
Output: [false, true, true, false, false]


Expected Time Complexity : O(queries.length + n + edges.length)

*/