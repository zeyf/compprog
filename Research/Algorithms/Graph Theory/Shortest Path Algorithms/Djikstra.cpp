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

void djikstra(WeightedGraph<char> &graph, char start, char end) {

    /*
    Get all vertices, get vertices count, initialize the distances, parents, indexCharacter, and characterIndexMap
    */
    unordered_set<char> vertices = graph.getVertices();
    const int V = sz(vertices);
    vector<ll> distances(V, 10e12);
    vector<char> parents(V, '_');
    vector<int> indexCharacter(V);
    unordered_map<char, int> characterIndexMap;

    // store the bidirectional relationship between node labels and indexes...
    auto it = vertices.begin(); int i = 0;    
    while (it != vertices.end()) {
        indexCharacter[i] = *it; 
        characterIndexMap[*(it++)] = i++;
    };

    // initialize q. Also default distance of start node to 0.
    // Add to queue, and make the parent of the current node the node itself.
    set<pair<int, char>> q;
    distances[characterIndexMap[start]] = 0;
    q.insert(make_pair(0,start));
    parents[characterIndexMap[start]] = characterIndexMap[start];

    // while we have not explored all minimizing vertices...
    while (sz(q)) {

        // get the current node. The beginning of the set (since ordered by weight) will be the smallest.
        // erase the entry.
        auto c = q.begin(); char cnode = c->se;
        q.erase(c);
        // cout << cnode nl;

        // get the edges of the current node
        vector<pair<int, char> > edges = graph.getVertexEdges(cnode);
        
        // iterate over the edges from the current node to its neighbors
        for (auto nbr: edges) {

            // get the weight of the edge and the node
            int c_to_nbr_weight = nbr.fi; char nbrnode = nbr.se;

            // if the distance of the current node + the weight of the edge to neighbor is lesser than the distance of the neighbor, we found a shorter path to this node.
            if (distances[characterIndexMap[cnode]] + c_to_nbr_weight < distances[characterIndexMap[nbrnode]]) {
                
                // erase any previous entry that could have been tied to the current node. if first time seeing, nothing will be found, else it would.
                // update the distance to neighbor to be the distance to current node + weight between current node to neighbor.
                // mark the parent of the neighbor node to be the current node.
                // insert into the queue the new entry of the new weight of the neighbor node and its name.
                q.erase(make_pair(distances[characterIndexMap[nbrnode]], nbrnode));
                distances[characterIndexMap[nbrnode]] = distances[characterIndexMap[cnode]] + c_to_nbr_weight;
                parents[characterIndexMap[nbrnode]] = characterIndexMap[cnode];
                q.insert(make_pair(distances[characterIndexMap[nbrnode]], nbrnode));
            };
        };


    };


    // reconstruct the path from the start node to the end node in reverse (from end to start)
    vc path;
    char cPathNode = characterIndexMap[end];
    while (cPathNode != characterIndexMap[start]) {
        path.add(indexCharacter[cPathNode]);
        cPathNode = parents[cPathNode];
    };

    path.add(start);

    // Print the distance from start to end, and the path taken from start to end.
    cout << "From " << start << " to " << end << ":\t" << distances[characterIndexMap[end]] nl;
    int x; range(path.size()-1, -1, -1, x) {
        cout << path[x] << " ";
    };

    cnl;
}

int main () {

    int e; cin >> e;
    WeightedGraph<char> graph(false);

    // read in and add the edges to the graph
    while (e--) {
        char u, v; int w; cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    };

    // read in the start and end nodes
    char start, end; cin >> start >> end;
    djikstra(graph, start, end);

    return 0;
};