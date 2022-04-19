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

int main () {

    int n; string s; cin >> n >> s;

    if (s.size() <= 2) {
        cout << s << "\n";
        return 0;
    };

    string decoded;
    decoded.pushb(s[s.size()-2]);
    decoded.pushb(s[s.size()-1]);
    s.pop_back();
    s.pop_back();

    while (s.size() > 0) {
        if (s.size() & 1) {
            int m = decoded.size()>>1;
            decoded = decoded.substr(0, m) + string(1, s.back()) + decoded.substr(m);
        } else {
            int m = (decoded.size()-1)>>1;
            decoded = decoded.substr(0, m) + string(1, s.back()) + decoded.substr(m);
        };
        s.pop_back();
    };

    cout << decoded <<"\n";


};