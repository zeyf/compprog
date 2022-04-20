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

Link: https://codeforces.com/contest/688/problem/B

Topic: Geometry / Sorting

Solution: Use rules of non-degenerate triangles + sorting.

Time Complexity: O(NLogN)
Space Complexity: O(N)

*/

int main () {

    // read in
    int n, x; cin >> n; vll lines(n);
    range(0, sz(lines), 1, x)
        cin >> lines[x]; 

    // sort
    sort(lines.begin(), lines.end());

    // check all triplets
    int r = 2; bool good = false;
    while (r<n && !good) {
        ll a = lines[r-2], b = lines[r-1], c = lines[r];
        if (a+b>c && a+c>b && b+c>a) good = true;
        r++;
    };

    // print answer
    if (good) cout << "YES\n";
    else cout << "NO\n";

    return 0;
};