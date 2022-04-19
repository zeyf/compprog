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
typedef set<char> sc;

/*
VECTOR TYPEDEFS
*/

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pii > vpii;
typedef vector<char > vc;
typedef vector<pllll > vpllll;

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

https://codeforces.com/contest/451/problem/B

*/

bool comp(pllll a, pllll b) { 
    if (b.second != a.second)
        return b.second > a.second;
    else
        return b.first > a.first;
};

int main () {

    int n, f; cin >> n >> f;
    vpllll a;
    
    int x;
    range(0, n, 1, x) {
        ll k, l; cin >> k >> l;
        if (l == 0 || k == 0) continue;
        a.push_back(make_pair(k,l));
    };

    sort(a.begin(), a.end(), comp);

    ll ans = 0;
    while (a.size() > 0) {
        ll products = a.back().first, clients = a.back().second;
        if (f > 0) {
            products <<= 1;
            f--;
        };
        if (clients >= products)
            ans += products;
        else
            ans += clients;
        a.popb();
    }

    cout << ans << "\n";

    return 0;
};