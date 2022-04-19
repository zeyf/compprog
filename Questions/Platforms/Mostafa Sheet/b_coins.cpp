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

    vs exps(3);
    cin >> exps[0] >> exps[1] >> exps[2];
    int agreater = 0, bgreater = 0, cgreater = 0;

    int x;
    range(0, 3, 1, x) {
        string s = exps[x];
        if (s == "A>B" || s == "B<A")
            agreater++;
        else if (s == "A>C" || s == "C<A") {
            agreater++;
        } else if (s == "B>A" || s == "A<B") {
            bgreater++;
        } else if (s == "B>C" || s == "C<B") {
            bgreater++;
        } else if (s == "C>A" || s == "A<C")
            cgreater++;
        else if (s == "C>B" || s == "B<C")
            cgreater++;
        else if (s == "A>A" || s == "A<A")
            agreater++;
        else if (s == "B>B" || s == "B<B")
            bgreater++;
        else if (s == "C>C" || s == "C<C")
            cgreater++;
    };

    if ((agreater > 2 || bgreater > 2 || cgreater > 2)) {
        cout << "Impossible\n";
        if (agreater > 2) { cout << "A";} else if (bgreater > 2) cout < "b"; else cout << "c";
    }
    else {
        if (agreater == 2) {
            if (cgreater > 0)
                cout << "BCA";
            else
                cout << "CBA";
        } else if (bgreater == 2) {
            if (agreater > 0)
                cout << "CAB";
            else
                cout << "ACB";
        } else {
            if (agreater > 0)
                cout << "BAC";
            else
                cout << "ABC";
        }

        cout << "\n";
    }

    return 0;
};