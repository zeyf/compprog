#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*DEFINES*/

#define add push_back
#define rem pop_back
#define ins insert
#define co count
#define fi first
#define se second
#define sorter(a, comp) sort(a.begin(), a.end(), comp)
#define sz(a) a.size()


/*
TYPEDEFS
*/

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pllll;

/*
SET TYPEDEFS
*/

typedef set<int> si;
typedef set<ll> sll;
typedef set<string> ss;
typedef set<pii > spii;
typedef set<pllll > spllll;

/*
VECTOR TYPEDEFS
*/

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pii > vpii;

/*
MAP TYPEDEFS
*/

typedef map<int, int> mii;
typedef map<ll, ll> mllll;
typedef map<string, int> msi;
typedef map<char, int> mci;
typedef map<int, vi > mivi;
typedef map<string, vs > msvs;
typedef map<int, unordered_set<int> > miusi;

/*

LINK


Topic: Graph Theory (BFS)

STRATEGY

I pretty much multi source bfs topo sorted an undirected graph to some degree. I realized this after AC.


*/

int main () {

    // Read in the inputs
    int n, e; cin >> n >> e;

    // initialize the unordered_set adjacency list
    miusi adj;

    // read in the edges
    while (e--) {
        int u, v; cin >> u >> v;
        adj[u].ins(v); adj[v].ins(u);
    }

    // initialize the queue and the visited set
    queue<int> q;
    si seen;

    // find all nodes that are leaves
    auto it = adj.begin();
    while (it != adj.end()) {
        // if a node has only one neighbor, it is a leaf
        // add it to the queue and mark as visited
        if (sz(it->second) == 1) {
            q.push(it->first);
            seen.ins(it->first);
        }
        it++;
    }

    // tracks how many levels of leafs found
    int leafFoundLevel = 0;

    // while we haven't processed the full graph...
    while(sz(q) > 0) {
        // to see if we found a leaf after going through a full bfs level.
        bool foundLeaf = false;
        int SIZE = sz(q);

        // iterate and process the whole level at once...
        while (SIZE--) {
            // take the current queue element...
            int u = q.front(); q.pop();

            // if the current element only has one neighbor...
            if (sz(adj[u])==1) {
                // mark that we have found a leaf node on the level and direct an edge from u to v. remove the edge from v to u. this effectively "topo sorts"
                foundLeaf = true;
                adj[*(adj[u].begin())].erase(u);
            }

            // iterate through the node's neighbors...
            auto neighbors = adj[u].begin();
            while (neighbors != adj[u].end()) {
                int v = *neighbors;

                // if the neighbor has not been visited and the neighbor only has 1 edge... go!
                if (!seen.co(v) && sz(adj[v])==1) {
                    // mark visited, add to queue.
                    seen.ins(v);
                    q.push(v);
                };

                neighbors++;
            }
        };

        // if we have found a leaf, keep going, we aren't done yet! Else, we can't reduce the graph any more. stop now.
        if (foundLeaf) leafFoundLevel++;
        else break;
    };

    // print the answer!
    cout << leafFoundLevel << "\n";


    return 0;
};