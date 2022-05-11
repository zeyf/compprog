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

#define debug(x) cout << #x " : " << x << "\n";

/*

Link: https://codeforces.com/contest/1676/problem/F

Topic: Greedy / Sorting / Two Pointers / Contiguous Intervals

Approach: Read in the numbers into a map for frequency counting. If frequency >= k, add to vector.
Iterate through vector, be greedy and take the maximal contiguous value interval.

Time Complexity: O(NlogN)
Space Complexity: O(N)

*/

int main () {

    // tc test cases...
    int tc; cin >> tc;
    while (tc--) {
        
        // read in number of words and min k times appearance to consider...
        int n, k; cin >> n >> k;
        map<ll, ll> frequencies;

        // read the data into a map for frequency counting!
        /*
        This has multiple purposes...
        This compresses the data, sorts, and will be used to prune search space
        */
        while (n--) {
            ll v; cin >> v;
            if (!frequencies.co(v))
                frequencies[v]=1;
            else
                frequencies[v]++;
        };

        // this step "prunes" the search space, since ignore invalid cases (frequency < k)
        vector<pair<ll,ll> > pairs;
        auto it = frequencies.begin();
        while (it != frequencies.end()) {
            if (it->second >= k)
                pairs.push_back(make_pair((ll)it->first, (ll)it->second));
            it++;
        };

        // if we have nothing that is frequented >= k, no answer. print -1, go to next test case.
        if (pairs.size() == 0) {
            cout << -1 << "\n";
            continue;
        }

        // classic interval setup!
        int startIndex = 0, endIndex = 0;

        // to track the best answer of valid contiguous intervals...
        ll maxL = -1, maxR = -1;

        // iterate over the { value, frequency }  pairs
        int x; range(0, pairs.size(), 1, x) {
            pllll startPair = pairs[startIndex], endPair = pairs[endIndex], currPair = pairs[x];

            // if we broke the contiguous value property needed for intervals, for example: 13 > 11 + 1
            if (currPair.first > endPair.first + 1) {
                // if we fou
                if (abs(startPair.first-endPair.first) > abs(maxL-maxR)) {
                    maxL = startPair.first, maxR = endPair.first;
                };
                startIndex = endIndex = x;
            // cant be equal, due to map uniqueness, so will be less than currPair.first, greater than endPair. meaning this can only be endPair.first + 1
            // extend the interval
            } else {
                endIndex = x;
            }

        };

        // catch the final state at the last index if better answer is possible
        if (abs(pairs[endIndex].first - pairs[startIndex].first) >= abs(maxL-maxR)) {
            maxL = pairs[startIndex].first, maxR = pairs[endIndex].first;
        }

        // print answer
        cout << maxL << " " << maxR nl;

    }

    return 0;
};