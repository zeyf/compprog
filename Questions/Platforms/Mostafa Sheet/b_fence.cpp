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

Link: https://codeforces.com/contest/363/problem/B

Topic: Prefix Sum / Sliding Window / Two Pointer

Solution: Make prefix sum array, and tested all windows of size k for maximal window sum.

Time Complexity: O(N)
Space Complexity: O(N)

*/

int main () {

    // Read in the constraints
    int n, k, x; cin >> n >> k;

    // initialize the 1-indexed pf sum array and build it.
    vi pf(n+1);
    cin >> pf[1];
    range(2, n+1, 1, x) {
        cin >> pf[x];
        pf[x] += pf[x-1];
    };

    // Track minsum and the minidx of the start of each minimal window.
    int minidx = 1, minsum = pf[k];
    int l = 2, r = k+1;

    // while we have not seen all windows.
    while (r <= n) {
        // Calculate current window sum by taking rightbound and summing out the prefix sum of element to left of desired left.
        // this will remove subset of the prefix sum that comes before the desired left bound.
        int csum = pf[r]-pf[r-k];
        if (minsum > csum) {
            minsum = csum;
            minidx = r-k+1;
        };

        // slide the window to the right by one.
        l++; r++;
    };

    // print the answer
    cout << minidx << "\n";

    return 0;
};