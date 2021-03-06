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

mllll dp;


ll f(ll n, ll m, ll k) {
    if (k < 0 ||) return 0;
    else if (dp.count(k) && n == 0) return dp[k];
    else if (n == 0) {
        return dp[k] = 1;
    }
    int x; range(m, 0, -1, x) {
        dp[k] += f(n-1,m,k-x) % 998244353;
    };

    return dp[k];
};

int main () {

    ll n, m, k; cin >> n >> m >> k;

    int x; range(0, 7, 1, x) {
        dice.push_back(x);
    };

    dp[0] = 1;
    f(n,m,k);
    cout << dp[k] << "\n";

    return 0;
}