#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*DEFINES*/

#define pushb push_back
#define popb pop_back
#define ins insert
#define co count
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

https://codeforces.com/contest/514/problem/B

*/

int main () {

    set<pair<double, double> > lines;
    set<int> xints, yints;

    int n, gunx, guny; cin >> n >> gunx >> guny;

    while (n--) {
        int x, y; cin >> x >> y;
        if (gunx-x == 0) {
            xints.ins(x);
        } else if (guny-y == 0) {
            yints.ins(y);
        }else {
            double slope = (guny-y)/(gunx-x);
            double b = y-(slope*x);
            lines.ins(make_pair(slope, b));
        }
    };

    cout << sz(lines)+sz(xints)+sz(yints) << "\n";

    return 0;
};