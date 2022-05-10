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

#define MAX (ll)10e16
vector<vll > adjmatrix(501, vll(501, MAX));
vector<vll > floydmatrix(501, vll(501, MAX));
vector<vll > subgraphmatrix(501, vll(501, MAX));
vi repairshops;
mivi strippedGraph;

// implements Floyd-Warshall to find APSP between all nodes.
void floyd(int n) {
    int x,y,z;
    range(1, n+1, 1, z)
        range(1, n+1, 1, x)
            range(1, n+1, 1, y)
                floydmatrix[x][y] = min(floydmatrix[x][y], floydmatrix[x][z] + floydmatrix[z][y]);
};

// strips the graph to just include the home, school, and all repair shops and adds edges between
// all of the pairs of these that do not exceed the initial air in the teime.
// if we ever exceed the distance, there is point in adding a pair.
// after this function, we have all distances
void stripGraph(int d) {
    for (int x = 0; x < sz(repairshops); x++) {
        for (int y = x+1; y < sz(repairshops); y++) {
            if (floydmatrix[repairshops[x]][repairshops[y]] > d) continue;
            strippedGraph[repairshops[x]].add(repairshops[y]), strippedGraph[repairshops[y]].add(repairshops[x]);
        };
    };
};


// implements Bellman-Ford to find the SSSP from home to school.
void bellmanford(int n) {
    vector<ll> distances(501, MAX);
    distances[1] = 0;

    // relax edges V-1 times
    int x; range(0, n-1, 1, x) {
        auto it = strippedGraph.begin();
        bool relaxedEdge = false;
        while (it != strippedGraph.end()) {
            int u = it->first;
            for (auto v: strippedGraph[u])
                if (distances[u] != MAX && distances[u] + floydmatrix[u][v] < distances[v])
                    distances[v] = distances[u] + floydmatrix[u][v], relaxedEdge = true;
            it++;
        };

        if (!relaxedEdge) break;
    };

    if (distances[n] == MAX) cout << "stuck" nl;
    else cout << distances[n] nl;
};


int main () {
    
    // read in the constraints
    int n, m, t, d; cin >> n >> m >> t >> d;

    // read in the repair shop nodes
    int t_it = t;
    while (t_it--) {
        int rpshop; cin >> rpshop;
        repairshops.add(rpshop);
    };

    // these two can be counted as repairshops, since they either start full or are fine ending at 0 air here.
    repairshops.add(1); repairshops.add(n);

    // read in and set the edges in the adjmatrix and the floyd matrix
    int m_it = m;
    while (m_it--) {
        int u, v, w; cin >> u >> v >> w;
        adjmatrix[u][v] = adjmatrix[v][u] = floydmatrix[u][v] = floydmatrix[v][u] = w;
    };

    floyd(n);
    stripGraph(d);
    bellmanford(n);

    return 0;
};