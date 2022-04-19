#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <math.h>
#include <string>


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

int main () {

    int n; string s; cin >> n >> s;

    pii pos = make_pair(0,0);
    char c = 'E';

    for (char d: s) {
        if (d == 'S') {
            if (c == 'E') pos.first++;
            else if (c == 'W') pos.first--;
            else if (c == 'N') pos.second++;
            else pos.second--;
        } else {
            if (c == 'E')
                c = 'S';
            else if (c == 'S')
                c = 'W';
            else if (c == 'W')
                c = 'N';
            else
                c = 'E';
        };
    };

    cout << pos.first << " " << pos.second << "\n";

    return 0;
};