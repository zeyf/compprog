#include<bits/stdc++.h>
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*

There is a network of n computers, each computer is numbered 1 to n.
The computer network is given as an array of edges where edges[i] = { u_i, v_i } is a bidirectional edge that connects computer u_i and computer v_i.
Your task is to find if Alice can send a message to Bob. If it is possible, return the minimum number of computers on such a route.
If it is not possible, return -1.

Alice's computer is 1 and Bob's computer is n.

*/

int messageRoute(int n, vector<vector<int>> &edges)
{
    if (n == 1) return 1;
    
    map<int, vector<int> > adjlist;

    // Create the adjacency list.
    for (auto &edge: edges) {
        if (!adjlist.count(edge[0]))
            adjlist[edge[0]] = vector<int>();
        if (!adjlist.count(edge[1]))
            adjlist[edge[1]] = vector<int>();
        adjlist[edge[0]].push_back(edge[1]);
        adjlist[edge[1]].push_back(edge[0]);
    };
    
    // Initialize the queue of (node, count) and the set of visited nodes.
    queue<pair<int, int> > q;
    set<int> visited;
    q.push(make_pair(1, 1));
    visited.insert(1);
    
    // BFS
    while (q.size() > 0) {
        pair<int, int> c = q.front();
        q.pop();

        // for all neighbors of current...
        for (auto &nbr: adjlist[c.first]) {
            // If we have not been to a given neighbor
            if (!visited.count(nbr)) {
                // if it is n, cut off early, we found it no need to process the rest of the graph or queue.
                if (nbr == n) {
                    return c.second+1;
                }

                // add in the neighbor to visited and push on the neighbor along with it's propagated node count from source.
                visited.insert(nbr);
                q.push(make_pair(nbr, c.second+1));
            };
        };
    };
    
    // If the set of Alice is disjoint with the set of Bob...
    return -1;
};