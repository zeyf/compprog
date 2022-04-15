#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
#define pb push_back
#define itr iterator
typedef vector<int> vi;
typedef map<int, vector<int > > mpivi;
typedef set<int> si;

mpivi normalGraph, transposedGraph;
si kosarujuVisited, cyclicSCCs;
vi normalPostorder, currentSCC, singletonSCCs;

/*
https://atcoder.jp/contests/abc245/tasks/abc245_f
*/

// perform first dfs to get graph post order
void kosaruju1(int u) {
    // add node to visited set
    kosarujuVisited.insert(u);

    // if the node exists in the normalGraph (aka has an outdegree > 0), visit all neighbors
    if (normalGraph.count(u)) {
        int x; range(0,normalGraph[u].size(), 1, x) {
            int v = normalGraph[u][x];
            if (!kosarujuVisited.count(v))
                kosaruju1(v);
        }
    }

    // collect postorder of normal graph
    normalPostorder.pb(u);
};

// perform second dfs on transposed graph
void kosaruju2(int u) {
    // add node to visited set
    kosarujuVisited.insert(u);

    // if the node exists in the transposedGraph (aka has an outdegree > 0), visit all neighbors
    if (transposedGraph.count(u)) {
        int x; range(0,transposedGraph[u].size(), 1, x) {
            int v = transposedGraph[u][x];
            if (!kosarujuVisited.count(v))
                kosaruju2(v);
        }
    }

    // store the current SCC
    currentSCC.pb(u);
};

// find all descendants of a given singleton SCC that have an edge to a non singleton cyclic SCC
// specifically runs on the normal graph after identifying SCCs.
// The cyclic SCCs will stay the same regardless of normal or transposed graph
// The singleton SCCs will NOT direct and share the same relationship towards SCCs on the transposed graph and the normal graph.
// We care about the cyclic SCCs and the singleton SCCs (if they connect to these cyclic SCCs) as we were given the graph.
// This is why this transposition and then reevaluation of the original graph is important.
void findCyclicSCC(int u) {
    // add node to visited set
    kosarujuVisited.insert(u);

    // if the node exists in the transposedGraph (aka has an outdegree > 0), visit all neighbors
    if (normalGraph.count(u)) {
        int x; range(0, normalGraph[u].size(), 1, x) {
            int v = normalGraph[u][x];

            // If we found an edge from u to v, where v is a node of a cyclic SCC in the graph, mark u as contributing to cyclic behavior
            if (cyclicSCCs.count(v)) {
                cyclicSCCs.insert(u);
                continue;
            };

            // if v does not belong to a cyclicSCC and we have not visited it
            if (!kosarujuVisited.count(v)) {
                // visit neighbor and descendants
                findCyclicSCC(v);
                // if after exploring the descedants of v, we realize that v has a descendant with an edge to a cyclicSCC,
                // assume cyclic behavior and propagate it upwards to the ancestors.
                if (cyclicSCCs.count(v))
                    cyclicSCCs.insert(u);
            };
        }
    }
};

int main () {

    int n, m; cin >> n >> m;

    // read in the edges
    while (m--) {
        int u, v; cin >> u >> v;
        normalGraph[u].pb(v);
        transposedGraph[v].pb(u);
    };

    int x;

    // get the postorder of the normal graph
    range(1, n+1, 1, x) {
        if (!kosarujuVisited.count(x)) {
            kosaruju1(x);
        };
    };

    // clear the set for next use
    kosarujuVisited.clear();

    // iterate through the postorder from last out to first out
    while (normalPostorder.size() > 0) {
        int u = normalPostorder.back();
        // if this node has not been visited in the transposed graph...
        if (!kosarujuVisited.count(u)) {
            // DFS into the node in the transposed graph.
            kosaruju2(u);
            
            // There exist SCCs of 1 vertex, they are singleton SCCs. If we find one composed of more than 1 vertex,
            // we have found a cyclic SCC (since this is a simple graph, no self loops)...
            if (currentSCC.size() > 1) {
                // mark all the cyclicSCCs
                int y; range(0, currentSCC.size(), 1, y) {
                    cyclicSCCs.insert(currentSCC[y]);
                };
            
                // store the singleton SCCs for DFS evaluation.
            } else
                singletonSCCs.pb(u);

            // clear the currentSCC vector for next possible SCC.
            currentSCC.clear();
        };

        // remove the current node. we either DFS'd to it just now, or we did via a neighbor.
        normalPostorder.pop_back();
    };

    // clear for next DFS
    kosarujuVisited.clear();

    // iterate over all the singleton SCCs.
    range(0, singletonSCCs.size(), 1, x){
        // if we have not visited them...
        if (!kosarujuVisited.count(singletonSCCs[x])) {
            // dfs to find any descedant edges to cyclic SCCs.
            findCyclicSCC(singletonSCCs[x]);
        };
    };

    cout << cyclicSCCs.size() << "\n";

    return 0;
}