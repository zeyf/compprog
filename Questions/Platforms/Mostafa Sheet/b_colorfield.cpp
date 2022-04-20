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


/*

LINK



STRATEGY



*/

int main () {

    int n, m, w, q; cin >> n >> m >> w >> q;

    vector<vs > grid(n, vs(m, "Waste"));
    spii wasted;

    while (w--) {
        int u, v; cin >> u >> v; wasted.ins(make_pair(u-1,v-1));
    }

    int x, y, ptr = 0;
    vs options = { "Carrots", "Kiwis", "Grapes" };
    range(0, n, 1, x) {
        range(0, m, 1, y) {
            if (!wasted.co(make_pair(x, y))) {
                grid[x][y] = options[ptr];
                ptr = (ptr+1)%3;
            }
        }
    }

    while (q--) {
        int u, v; cin >> u >> v; cout << grid[u-1][v-1] << "\n";
    };

    return 0;
};