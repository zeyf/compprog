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

Link: https://codeforces.com/contest/1676/problem/B

Topic: Greedy / Math

Approach: Normalize the boxes that are greater than min(boxes) to be equal to min. Sum the difference between mini and any given greater box.

Time Complexity: O(N)
Space Complexity: O(N)

*/

int main () {

    // tc test cases...
    int tc; cin >> tc;
    while (tc--) {

        // read in boxes and track the minimum of the boxes candy count.
        int n; cin >> n;
        vll boxes;
        ll mini = 10e16;
        while (n--) {
            ll box; cin >> box; boxes.add(box);
            mini = min(mini, box);
        };

        // take sum of normalization distance for each box if greater than the minimum needed.
        ll ans = 0;
        for (auto box: boxes) {
            if (box > mini)
                ans += box - mini;
        };

        // print answer
        cout << ans nl;
    }


    return 0;
};