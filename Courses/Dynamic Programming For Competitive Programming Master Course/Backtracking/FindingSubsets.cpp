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

/*
MAP TYPEDEFS
*/

typedef map<int, int> mii;
typedef map<ll, ll> mllll;
typedef map<string, int> msi;
typedef map<char, int> mci;
typedef map<int, vi > mivi;
typedef map<string, vs > msvs;

// recursive subsets

// Time Complexity: O(2^n)
// Space Complexity: O(2^n)
void subsets(string base, int k = 0, string built = "") {
    if (k == sz(base)) {
        cout << built nl;
        return;
    }

    // don't take
    subsets(base, k+1, built);
    // take
    subsets(base, k+1, built+base[k]);
};



int main () {

    string str = "yo";
    subsets(str);

    cout nl nl nl;
    // iterative subsets.
    // Time Complexity: O(n*2^n)
    // Space Complexity: O(1)
    int subset; range(0, 1<<sz(str), 1, subset) {
        int x; range(0, sz(str), 1, x) {
            if ((subset & (1<<x)) != 0)
                cout << str[x];
        };
        
        cnl;
    };


    return 0;
};