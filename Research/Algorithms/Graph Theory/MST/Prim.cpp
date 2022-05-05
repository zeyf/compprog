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
#define nl << "\n"
#define cnl cout << "\n"


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
typedef vector<char> vc;
typedef vector<vc > vvc;
typedef vector<vi > vvi;

/*
MAP TYPEDEFS
*/

typedef map<int, int> mii;
typedef map<ll, ll> mllll;
typedef map<string, int> msi;
typedef map<char, int> mci;
typedef map<int, vi > mivi;
typedef map<string, vs > msvs;

template<typename T>
class WeightedGraph {

public:
    WeightedGraph(bool undir);

    void addEdge(T u, T v, int w) {
        adjlist[u].push_back(make_pair(w,v));
        if (undirected) adjlist[v].push_back(make_pair(w,u));
        vertices.insert(u); vertices.insert(v);
    };

    unordered_set<T> getVertices() {
        return vertices;
    };

    vector<pair<int, T> > getVertexEdges(T u) {
        return adjlist[u];
    }

private:
    unordered_map<T, vector<pair<int, T> > > adjlist;
    unordered_set<T> vertices;
    bool undirected;

};

template <typename T>
WeightedGraph<T>::WeightedGraph(bool undir) {
    undirected = undir;
    vertices = unordered_set<T>();
};

void prim(WeightedGraph<int> &graph, int start) {
    // initialize the priority queue for weighted edges.
    // get the vertices in the graph.
    // initialize the visited vector and the mst vector.
    priority_queue<pair<int, pii >, vector<pair<int, pii > >, greater<pair<int, pii > > > pq;
    unordered_set<int> vertices = graph.getVertices();
    const int V = sz(vertices);
    vector<bool> visited(V, false);

    // lambda to add all unvisited edges of a given node u.
    auto addEdges = [&](int u) {
        for (auto e: graph.getVertexEdges(u)) {
            int minActiveEdgeVNeighborWeight = e.fi, minActiveEdgeVNeighbor = e.se;
            if (!visited[minActiveEdgeVNeighbor]) {
                pq.push(make_pair(minActiveEdgeVNeighborWeight, make_pair(u, minActiveEdgeVNeighbor)));
            }
        };
    };

    // add in all of the edges starting from the start node.
    addEdges(start);
    // mark start node as visited.
    vector<pair<int, pii > > mst;
    visited[start] = true;
    int cost = 0;

    // while we have not processed all edges or edge count < V-1, as per tree definition
    while (!pq.empty() && sz(mst) < V-1) {
        // get the minimum active edge, pop off priority queue
        auto minActiveEdge = pq.top(); pq.pop();
        int minActiveEdgeWeight = minActiveEdge.fi,
            minActiveEdgeU = minActiveEdge.se.fi, minActiveEdgeV = minActiveEdge.se.se;

        // if adding this edge creates a cycle, continue.
        if (visited[minActiveEdgeU] && visited[minActiveEdgeV]) {
            cout << "BAD: " << minActiveEdgeU << " " << minActiveEdgeV nl;
            continue;
        
        // else, we can add this edge.
        } else
            cout << "GOOD: " << minActiveEdgeU << " " << minActiveEdgeV nl;

        
        // account for the cost, visit the unvisited node (always will be V), push edge to mst.
        cost += minActiveEdgeWeight;
        visited[minActiveEdgeV] = true;
        mst.push_back(make_pair(minActiveEdgeWeight, make_pair(minActiveEdgeU, minActiveEdgeV)));

        // this check is specifically for directed graphs where a node may not exist in adjacency list (out degree of 0)
        // if so, add edges of that node.
        if (vertices.co(minActiveEdgeV))
            addEdges(minActiveEdgeV);

    };

    // print out the mst and cost.
    for (auto mst_e: mst) {
        cout << mst_e.second.first << " " << mst_e.second.second << ": " << mst_e.first nl; 
    };

    cout << "TOTAL COST: " << cost nl;

};

int main () {

    WeightedGraph<int> graph(true);
    int e; cin >> e;
    while (e--) {
        int u, v, w; cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    };

    int start; cin >> start;
    prim(graph, start);

    return 0;
};