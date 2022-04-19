#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <math.h>
 
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

    int n; cin >> n;
    si unique;
    int MAX = (n<<1)+1;
    while (unique.size() != MAX) {
        int x; range(1, MAX+1, 1, x) {
            if (!unique.count(x)) {
                unique.ins(x);
                cout << x << endl;
                fflush(stdout);
                break;
            }
        };
        cin >> n;
        if (n == 0) break;
        unique.ins(n);
    };

    return 0;
};