#include<bits/stdc++.h>
using namespace std;

typedef map<int, vector<int> > mivi;
typedef set<int> si;

void dfs(int u, mivi &graph, si &visited, vector<int> &vect) {
    visited.insert(u);
    for (auto v: graph[u])
        if (!visited.count(v))
            dfs(v, graph, visited, vect);
    vect.push_back(u);
}

bool solve(int n, vector<vector<int>> roads) {
    mivi nGraph, tGraph;
    for (auto e: roads)
        nGraph[e[0]].push_back(e[1]), tGraph[e[1]].push_back(e[0]);
    
    vector<int> postorder;
    si visited;
    for (int u = 0; u < n; ++u)
        if (!visited.count(u))
            dfs(u, nGraph, visited, postorder);

    visited.clear();
    while (postorder.size() > 0) {
        int u = postorder.back();

        if (!visited.count(u)) {
            vector<int> currentSCC;
            dfs(u, tGraph, visited, currentSCC);
            if (currentSCC.size() == n) return true;
        };

        postorder.pop_back();
    };

    return false;
}

/*

Graph Theory Algorithms for Competitive Programming (2022)
Connected Cities
You are given n cities represented as an integer in [0, n) and a list of one-way roads that connect one city to another.

Return whether you can reach any city from any city.

Constraints

n ≤ 10,000

m ≤ 100,000 where m is the length of roads

Example:

Input

n = 2
roads = [
    [0, 1],
    [1, 0]
]
Output

true
Explanation

You can go 0 to 1 and 1 to 0



Expected Time Complexity: O(n+m)

*/