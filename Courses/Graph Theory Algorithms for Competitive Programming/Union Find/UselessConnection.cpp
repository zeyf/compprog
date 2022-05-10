#include<bits/stdc++.h>
using namespace std;

typedef map<int, vector<int>> mivi;

/*

Approach: Find and preserve the cycle using a stack for the cycle
Then added these edges into a set or into a Union Find. Union the cycle path's adjacent pairs as they are edges.
Then return the answer.

*/

bool dfs(int u, int p, mivi &graph, set<int> &visited, vector<int> &cycleStack) {
    // visited the current node and add onto the cycle stack.
    visited.insert(u);
    cycleStack.push_back(u);

    // go to neighbors
    for (auto v: graph[u]) {
        // if the parent of the current node, do not consider
        if (v == p) continue;
        
        // if unvisited, dfs. If this recursion is true, we have found the cycle and it is preserved in the cycleStack.
        if (!visited.count(v)) {
            if (dfs(v, u, graph, visited, cycleStack))
                return true;
        // if we found the backedge...
        } else {
            // reverse the cycle stack to remove any possible nodes that are not a part of the cycle
            reverse(cycleStack.begin(), cycleStack.end());

            // since only the start of the traversal (front of cycleStack) can have non cycle nodes, pop until the backedge ancestor is seen.
            // it will always be there.
            while (cycleStack.back() != v) cycleStack.pop_back();

            // then reverse it back and add on the current node. now we have the full subgraph of the cycle in the cycle stack.
            // the adjacent pairs of nodes represent edges.
            // we must complete the back edge (we have current, but must add the ancestor as well)
            reverse(cycleStack.begin(), cycleStack.end());
            cycleStack.push_back(v);

            // backtrack! stop search.
            return true;
        };
    }
    
    // if we have not found the cycle in the current subtree, backtrack the cycle stack and return false.
    cycleStack.pop_back();
    return false;
};

vector<int> findUselessConnection(vector<vector<int>> edges) {
    // initialize the graph, visited set, and the cycle stack.
    mivi graph;
    set<int> visited;
    vector<int> cycleStack;

    // construct the undirected graph
    for (auto e: edges)
        graph[e[0]].push_back(e[1]), graph[e[1]].push_back(e[0]);
    
    // perform DFS.
    dfs(1, 1, graph, visited, cycleStack);

    // make the adjacent pairs into pairs...
    set<pair<int, int> > cycleEdges;
    for (int x = 0; x < cycleStack.size()-1; ++x)
        cycleEdges.insert(make_pair(cycleStack[x], cycleStack[x+1]));
    
    // return the latest cycle edge from input, or an empty array if there is no cycle
    vector<int> ans;
    for (int x = edges.size()-1; x >= 0; x--)
        if (cycleEdges.count(make_pair(edges[x][0], edges[x][1])) || cycleEdges.count(make_pair(edges[x][1], edges[x][0])))
            return edges[x];
    return ans;
}

/*


Graph Theory Algorithms for Competitive Programming (2022)
Useless Connection
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

Constraints:

n == edges.length

3 <= n <= 1000

edges[i].length == 2

1 <= ai < bi <= edges.length

ai != bi

There are no repeated edges.

The given graph is connected.

Expected Time Complexity: O( n+m ), where m is the number of edges

*/