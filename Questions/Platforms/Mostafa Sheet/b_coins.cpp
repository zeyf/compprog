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

string swap(string s, int u, int v) {
    int t = s[u];
    s[u] = s[v];
    s[v] = t;
    return s;
}

int main () {

    vs exps(3,""); cin >> exps[0] >> exps[1] >> exps[2];

    if (exps[0][1] == '<') {
        exps[0] = swap(exps[0], 0, 2);
        exps[0][1] = '>';
    }

    if (exps[1][1] == '<') {
        exps[1] = swap(exps[1], 0, 2);
        exps[1][1] = '>';
    }

    if (exps[2][1] == '<') {
        exps[2] = swap(exps[2], 0, 2);
        exps[2][1] = '>';
    }

    set<char> lhs;
    vi counts(3,0);
    for (auto &exp: exps) {
        lhs.ins(exp[0]);
        counts[exp[0]-'A']++;
    };


    if (lhs.size()==3) {
        cout << "Impossible\n";
        return 0;
    };

    vs arranged;
    for (auto &exp: exps) {
        if (counts[exp[0]-'A'] == 2) {
            arranged.pushb(exp);
        }
    }

    for (auto &exp: exps) {
        if (counts[exp[0]-'A'] !=2) {
            arranged.pushb(exp);
        }
    }

    if (arranged.back()[2] == arranged[0][0]) {
        cout << "Impossible\n";
        return 0;
    };

    cout << arranged[2][2] << arranged[2][0] << arranged[0][0] << "\n";
    




    return 0;
};