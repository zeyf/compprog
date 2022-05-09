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

#define MAX (ll) 10e16
#define N 5
vector<vll >  adjmatrix(N, vll(N, MAX));
vector<vll >  floydmatrix(N, vll(N, MAX));

// print the current state of the APSP matrix
void printFloydMatrix() {
    int x, y; range(0, N, 1, x) {
        range(0, N, 1, y)
            printf("%20lld", floydmatrix[x][y]);
        cnl;
    };

    cnl; cnl;
}

// perform floyd warshall.
int floyd() {
    int x, y, z;
    printFloydMatrix();
    range(0, N, 1, z) {
        range(0, N, 1, x)
            range(0, N, 1, y)
                floydmatrix[x][y] = min(floydmatrix[x][y], floydmatrix[x][z] + floydmatrix[z][y]);
        cout << "INCLUDING: " << z nl;
        printFloydMatrix();
    };
};


int main () {

    // read in edges
    int e; cin >> e;
    while (e--) {
        int u, v, w; cin >> u >> v >> w;
        adjmatrix[u][v] = adjmatrix[v][u] = floydmatrix[u][v] = floydmatrix[v][u] = w;
    };

    // assume non reflexive (no self loops)
    int x; range(0, N, 1, x)
        if (floydmatrix[x][x]==MAX)
            floydmatrix[x][x] = 0;

    floyd();

    return 0;
};