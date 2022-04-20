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

/*

Link: https://codeforces.com/contest/47/problem/B

Topic: Adhoc / Implementation / Logic

Solution: 
- Get all expressions to be of format X > Y. If any is X < Y, flip to >, swap X and Y.
- If on left hand side there are 3 different letters, it's not possible as one has to be bigger than 2 by default.
- Take counts of the letters on left hand side.
- Add the 2 with count of 2 on LHS first to array
- Add the 1 with count of 1 on LHS to end of array
- If the last expression says greater than the greatest element, it's not possible
- Print the final statement...

Time Complexity: O(1)
Space Complexity: O(1)

*/

// swaps string characters
string swap(string s, int u, int v) {
    int t = s[u];
    s[u] = s[v];
    s[v] = t;
    return s;
}

int main () {
    
    // read in.
    vs exps(3,""); cin >> exps[0] >> exps[1] >> exps[2];

    unordered_set<char> lhs;
    vi counts(3,0);

    for (auto &exp: exps) {
        // flip the expressions to be X > Y
        if (exp[1] == '<') {
            exp = swap(exp, 0, 2);
            exp[1] = '>';
        }

        // insert LHS and count it.
        lhs.ins(exp[0]);
        counts[exp[0]-'A']++;
    };

    // 3 distinct characters on LHS...
    if (lhs.size()==3) {
        cout << "Impossible\n";
        return 0;
    };

    vs arranged;
    // add those of count 2 to arranged first...
    for (auto &exp: exps) {
        if (counts[exp[0]-'A'] == 2) {
            arranged.pushb(exp);
        }
    }

    // add that of count 1 to arranged last...
    for (auto &exp: exps) {
        if (counts[exp[0]-'A'] !=2) {
            arranged.pushb(exp);
        }
    }

    // if the last element says it's greater than the greatest... invalid.
    if (arranged.back()[2] == arranged[0][0]) {
        cout << "Impossible\n";
        return 0;
    };

    // print out solution...
    cout << arranged[2][2] << arranged[2][0] << arranged[0][0] << "\n";
    




    return 0;
};