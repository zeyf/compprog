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

/*

Link: https://codeforces.com/contest/1676/problem/C

Topic: Bruteforce / Greedy

Approach: Iterate over all pairs of strings. Compare the character differences at each index of their equal length strings.
Then be greedy and take the smallest difference.

Time Complexity: O(M*N^2)
Space Complexity: O(N)

*/

int main () {

    // tc test cases...
    int tc; cin >> tc;
    while (tc--) {

        // read in number of strings and their lengths and strings
        int n, m; cin >> n >> m;
        int x;

        // read in the words
        vector<string> words(n);
        range(0, n,1,x)
            cin >> words[x];

        // iterate over all pairs of strings
        ll ans = 10e16;
        int y,z;
        range(0, n, 1, x) {
            range(x+1, n, 1, y) {
                // iterate over each index of the pair of words, sum differences and take minimum.
                ll diff = 0;
                range(0, m, 1, z) {
                    diff += abs(words[x][z]-words[y][z]);
                };
                ans = min(ans, diff);
            };

        }

        // print answer
        cout << ans nl;
    };

    return 0;
};