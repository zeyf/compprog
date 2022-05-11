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

int n, m;
vvi board(201, vi(201, 0));

/*

Link: https://codeforces.com/contest/1676/problem/D

Topic: Bruteforce / Greedy

Approach: Go to every location in the grid. Iterate overall both diagonals fully -- no overlap.

Time Complexity: O(N*M*max(N,M))
Space Complexity: O(N*M)

*/

// gets full diagonal sum with no overlap.
ll getSum(int x, int y) {

    int a = x, b = y;
    ll sum = board[x][y];

    // up left diag
    a--, b--;
    while (a >= 0 && b >= 0)
        sum += board[a--][b--];

    // up right diag
    a = x-1, b = y+1;
    while (a >= 0 && b < m)
        sum += board[a--][b++];
    
    // bottom left diag
    a = x+1, b = y-1;
    while (a < n && b >= 0)
        sum += board[a++][b--];
    
    // bottom right adg
    a = x+1, b = y+1;
    while (a < n && b < m)
        sum += board[a++][b++];
    
    return sum;
};

int main () {

    // tc test cases...
    int tc; cin >> tc;
    while (tc--) {

        // read in dimensions.
        cin >> n >> m;

        // read in board
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m;  ++y) {
                cin >> board[x][y];
            };
        };

        ll ans = 0;
        // at every location calculate all diagonal sum. take the maximum.
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m;  ++y) {
                ans = max(ans,getSum(x,y));
            };
        };

        // print answer.
        cout << ans nl;
    }

    return 0;
};