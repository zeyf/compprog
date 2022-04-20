#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*DEFINES*/

#define pushb push_back
#define popb pop_back
#define ins insert
#define co count
#define sorter(a, comp) sort(a.begin(), a.end(), comp)
#define sz(a) sz.size()


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

Link: https://codeforces.com/contest/433/problem/B

Topic: Prefix Sums / Range Query / Sorting

Solution: Take prefix sum of regular permutation, and of sorted. Then, take queries.

Time Complexity: O(M + NlogN)
Space Complexity: O(N)

*/

int main () {

    // read in
    int n, m, l, r, x; cin >> n;
    vll og(n), so(n);
    range(0, og.size(), 1, x) {
        cin >> og[x];
        so[x] = og[x];
    };

    // sort the array to be sorted...
    sort(so.begin(), so.end());

    // build the prefix sum array for both arrays.
    vll pfog(n), pfso(n);
    pfog[0] = og[0];
    pfso[0] = so[0];
    range(1, n, 1, x) {
        pfog[x] = og[x] + pfog[x-1];
        pfso[x] = so[x] + pfso[x-1];
    };

    // perform m queries...
    cin >> m;
    while(m--) {

        // take in the type and range... remove 1 indexing.
        int type; cin >> type >> l >> r;
        l--; r--;

        // if query on the original array
        if (type == 1) {
            // if lower bound is 0, no need to sum out subset.
            if (l==0)
                cout << pfog[r];
            // lower bound doesn't start at 0, so sum out the subset of [0,l-1] from [0,r] to have [l,r]
            else
                cout << pfog[r]-pfog[l-1];
        } else {
            // if lower bound is 0, no need to sum out subset.
            if (l==0)
                cout << pfso[r];
            // lower bound doesn't start at 0, so sum out the subset of [0,l-1] from [0,r] to have [l,r]
            else
                cout << pfso[r]-pfso[l-1];
        };

        cout << "\n";
    };

    return 0;
};