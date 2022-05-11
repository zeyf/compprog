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

Link: https://codeforces.com/contest/1676/problem/E

Topic: Greedy / Sorting / Prefix Sum / Binary Search

Approach: Sorted in the candy in descending order, built a prefix sum array from them, and answered queries with lower_bound (binary search.)

Time Complexity: O(NlogN + QlogN)
Space Complexity: O(N)

*/

int main () {

    // tc test cases...
    int tc; cin >> tc;
    while (tc--) {
        // read in n and q
        int n, q; cin >> n >> q;

        // read in the sugar per candy
        vector<ll> candies;
        int x;
        range(0, n , 1, x) {
            ll sugar; cin >> sugar;
            candies.add(sugar);
        };

        // sort and then reverse the array to get in descending order
        sort(candies.begin(), candies.end());
        reverse(candies.begin(), candies.end());

        // calculate prefix sum
        range(0, n-1, 1, x)
            candies[x+1] += candies[x];

        // perform queries
        while (q--) {
            // read in sugar amount
            ll xj; cin >> xj;

            // binary search for min sugar needed.
            auto it = lower_bound(candies.begin(), candies.end(), xj);
            // if not found, it exceeded the sum of the original array. print -1.
            if (it == candies.end()) {
                cout << -1 << "\n";
            // else print the 1-indexed count of the prefix sum that represents the number of candy eaten for xj sugar.
            } else
                cout << (int)(it-candies.begin())+1 << "\n";
        }

    };


    return 0;
};