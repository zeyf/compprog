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

/****/

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
    map<T, vector<pair<int, T> > > adjlist;
    unordered_set<T> vertices;
    bool undirected;

};

template <typename T>
WeightedGraph<T>::WeightedGraph(bool undir) {
    undirected = undir;
    vertices = unordered_set<T>();
};

// recursively reconstructs the shortest path from end to start.
void reconstructPath(int u, vector<int> &parents, vector<int> &path) {
    if (u != parents[u]) reconstructPath(parents[u], parents, path);
    path.add(u);
};

// SSSP
void bellmanford(WeightedGraph<int> &graph, int start, int end) {

    // initialize the vertices, distance and parents array.
    unordered_set<int> vertices = graph.getVertices();
    const int V = sz(vertices);
    const ll MAX = 10e9;
    vector<ll> distances(V, MAX);
    vector<int> parents(V, -1);

    // auto printDistanceState = [&] () { int x; range(0, V, 1, x) { cout << distances[x] << " "; }; cnl; };

    // initialize distance of start node to 0, parent of start node to start node.
    distances[start] = 0, parents[start] = start;

    // relax all edges V-1 times... (each iteration, 1 edge paths built... then 2, then 3.... then V-1)
    // this makes perfect sense, any SSSP will be a tree.
    for (int x = 1; x <= V-1; ++x) {

        // iterate through vertices
        for (auto u: vertices) {
            // iterate through edges of a given vertex u
            for (auto v: graph.getVertexEdges(u)) {
                int uvweight = v.first, vnode = v.second;

                // if a worthwhile edge relaxation can be made... relax and store parent.
                if (distances[u] != MAX && distances[u] + uvweight < distances[vnode]) {
                    distances[vnode] = distances[u] + uvweight;
                    parents[vnode] = u;
                };
            };
        };

    };

    // detect the negative weight cycle if negative weights allowed
    for (auto u: vertices) {
        for (auto v: graph.getVertexEdges(u)) {
            int uvweight = v.first, vnode = v.second;
            // if an edge relaxation can be done after
            // fully calculating the SSSP from source to all nodes, we have negative weight cycle.
            if (distances[u] != MAX && distances[u] + uvweight < distances[vnode]) {
                cout << "Negative Weight Cycle Found!" nl;
                return;
            };
        };
    };

    // if the end is never reached therefroe no parent is set so there is no way to get there from start.
    if (parents[end] == -1) {
        cout << "NO PATH EXISTS" nl;
        return;
    };

    // reconstruct and print the SSSP from start to end.
    vector<int> path;
    reconstructPath(end, parents, path);
    cout << "PATH:\t"; for (auto u: path) cout << u << " "; cnl;
    cout << "PATH COST:\t" << distances[end] nl;
};

int main () {

    int e; cin >> e;
    WeightedGraph<int> graph(false);

    // read in and add the edges to the graph
    while (e--) {
        int u, v, w; cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    };

    // read in the start and end nodes
    int start, end; cin >> start >> end;
    bellmanford(graph, start, end);

    return 0;
};