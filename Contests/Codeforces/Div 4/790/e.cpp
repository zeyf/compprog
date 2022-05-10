#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

//common file for PBDS
#include<ext/pb_ds/assoc_container.hpp>
//including tree_order_statistics_node_update
#include<ext/pb_ds/tree_policy.hpp>
//namespace
using namespace __gnu_pbds;
 
//macro definition
#define ordered_set_less tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_set_more tree<long long, null_type, greater<long long>, rb_tree_tag, tree_order_statistics_node_update>

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



int main () {

    int tc; cin >> tc;
    while (tc--) {
        int n, q; cin >> n >> q;
        vector<ll> candies;
        int x;
        range(0, n , 1, x) {
            ll sugar; cin >> sugar;
            candies.add(sugar);
        };

        sort(candies.begin(), candies.end());
        reverse(candies.begin(), candies.end());
        range(0, n-1, 1, x)
            candies[x+1] += candies[x];



        while (q--) {
            ll xj; cin >> xj;

            auto it = lower_bound(candies.begin(), candies.end(), xj, greater<int>());
            if (it == candies.end()) {
                cout << "-1\n";
            } else
                cout << (int)(it-candies.begin())+1 << "\n";
        }


    };


    return 0;
};