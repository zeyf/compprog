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
typedef set<pii> spii;
typedef set<pllll> spllll;

/*
VECTOR TYPEDEFS
*/

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vi> vvi;

/*
MAP TYPEDEFS
*/

typedef map<int, int> mii;
typedef map<ll, ll> mllll;
typedef map<string, int> msi;
typedef map<char, int> mci;
typedef map<int, vi> mivi;
typedef map<string, vs> msvs;

template <typename T>
class SimpleGraph
{

public:
    SimpleGraph(bool undir);

    void addEdge(T u, T v)
    {
        adjlist[u].push_back(v);
        if (undirected)
            adjlist[v].push_back(u);

        vertices.insert(u);
        vertices.insert(v);
    };

    unordered_set<T> getVertices()
    {
        return vertices;
    };

    vector<T> getVertexEdges(T u)
    {
        return adjlist[u];
    }

private:
    map<T, vector<T>> adjlist;
    unordered_set<T> vertices;
    bool undirected;
};

template <typename T>
SimpleGraph<T>::SimpleGraph(bool undir)
{
    undirected = undir;
    vertices = unordered_set<T>();
};

// traverse the graph, mark visited, and add to corresponding vector.
void dfs(int u, SimpleGraph<int> &graph, vector<bool> &visited, vector<int> &vect)
{
    visited[u] = true;
    for (auto v : graph.getVertexEdges(u))
    {
        if (!visited[v])
            dfs(v, graph, visited, vect);
    };

    vect.add(u);
};

void kosaraju(SimpleGraph<int> &graph)
{

    // get the vertices
    unordered_set<int> vertices = graph.getVertices();
    const int V = sz(vertices);

    // initialize the transposed graph
    // initialize the visited and postorder vector
    SimpleGraph<int> transposedGraph(false);
    vector<bool> visited(V, false);
    vector<int> postorder;

    // get the postorder of the normal graph
    for (auto u : vertices)
    {
        // if unvisited, traverse to collect postorder of normal graph
        if (!visited[u])
            dfs(u, graph, visited, postorder);

        // builds the transposed graph
        for (auto v : graph.getVertexEdges(u))
            transposedGraph.addEdge(v, u);
    };

    // clear the visited vector
    int x;
    range(0, V, 1, x) visited[x] = false;

    // traverse the transposed graph in reverse postorder of normal graph (First seen, last in)
    int SCCIndex = 1;
    while (sz(postorder) > 0)
    {
        int u = postorder.back();

        // if unvisited, tranverse to collect SCCs
        if (!visited[u])
        {
            vector<int> currSCC;
            dfs(u, transposedGraph, visited, currSCC);

            // print the SCC
            cout << "SCC #" << SCCIndex++ << ":\t";
            for (auto memberOfSCC : currSCC)
                cout << memberOfSCC << " ";
            cnl;
        };

        // remove the node regardless of it was visited before if or not.
        postorder.rem();
    };
};

int main()
{

    // read in the number of edges
    int e;
    cin >> e;
    SimpleGraph<int> graph(false);

    // read in and add the edges to the graph
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    };

    // perform kosaraju
    kosaraju(graph);

    return 0;
};