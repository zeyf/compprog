#include<bits/stdc++.h>
using namespace std;

/*

Graph Theory Algorithms for Competitive Programming (2022)
Detecting an Odd Length Cycle
Given an undirected graph as an adjacency list, return whether the graph has an odd length cycle.

Constraints:

n, m ≤ 250 where n and m are the number of rows and columns in graph

Input

graph = [
    [1, 2, 3],
    [0, 2],
    [0, 1, 3],
    [0, 2]
]
Output

true
Explanation

One odd length cycle would be 0 -> 2 -> 1 -> 0



Expected  Time Complexity: O(n+m)

*/

/*

APPROACH:

Since this is an undirected graph, we want to track the current node and it's parent at any given point to not have a false positive on a cycle.
I am also tracking visited -- however I am also backtracking the visitation of a node after fully processing it's subgraph
I am taking a page out of Tarjan's Algorithm for Bridges and Articulation Points and tracking the in times of nodes.

By storing the in time of nodes and incrementing a timer on each recurse, I can know the time a node was seen at.
Whenever we find a backedge in the a given DFS tree, we will compare the intime of the current node with the ancestor of that node
Since the time is one indexed, if the absolute value difference between the current node and it's ancestor (non parent) to be odd,
we have found an odd length cycle in the graph.

Must remember to do + 1 on the abs of the intime! The intime abs will give us the number of edges between the current node and
the ancestor that fulfills the backedge. We must also account for the backedge itself as this completes the cycle! Else we just have a DFS tree.

*/

bool dfs(int u, int p, vector<vector<int>> &graph, set<int> &visited, vector<int> &intime, int timer = 1) {
    // visit and track the intime
    visited.insert(u);
    intime[u]=timer;

    // visit neighbors
    for (auto v: graph[u]) {
        // if parent, skip
        if (v==p)continue;

        // if not visited, dfs. if recursion is true, we prune the search.
        if (!visited.count(v)) {
            if (dfs(v, u, graph, visited, intime, timer+1))
                return true;
        
        // if we found a backedge
        } else {
            // if we have an odd length path including the backedge
            if (abs(intime[v]-intime[u]+1) % 2 == 1)
                return true;
        };
    };
    
    // backtrack possibly the current path may not produce one, but another will through this node.
    visited.erase(u);
    return false;
}

bool solve(vector<vector<int>> graph)
{
    // initialize the visited set and the intime array to maximum constraints
    set<int> visited;
    vector<int> intime(251*251, 0);
    // perform dfs on every node...
    for (int x = 0; x < graph.size(); x++) {
        if(dfs(x, x, graph, visited, intime))
            return true;
    }
    
    // odd length cycle not found, return false.
    return false;
}