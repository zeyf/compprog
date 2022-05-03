#include <bits/stdc++.h>
//#include <stdio.h>
 
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

Link: 

Topic: 

Solution:

*/

int main () {

    int vp, vd, t, f, c; cin >> vp >> vd >> t >> f >> c;

    int princessPos = vp*t, dragonPos = 0, bijous = 0;

    while (princessPos < c) {
        if (dragonPos+vd >= princessPos) {
            bijous++;
            dragonPos -= f*vd;
        } else
            dragonPos += vd;
        princessPos += vp;
    }

    cout << bijous << "\n";

    return 0;
};