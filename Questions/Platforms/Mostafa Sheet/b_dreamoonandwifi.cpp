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

Link: https://codeforces.com/contest/476/problem/B

Topic: Probability / Combinatorics / Bruteforce

Solution: Try all possible combinations where there was a ?. Count all valid combinations and divide by the search space.

Time Complexity: O(2^Q)
Space Complexity: O(2^Q)

*/

int f(string s, int plusLeft, int minusLeft, int x) {

    // if have closed the search space on the current combination...
    if (x == sz(s)) {
        // if we have normalized the string...
        if (plusLeft == 0 && minusLeft == 0) {
            return 1;
        
        // if we have not normalized the string
        }else
            return 0;
    }

    int valid = 0;

    // if we must choose + or -
    if (s[x]=='?') {
        // take the + path.
        s[x] = '+';
        valid += f(s, plusLeft-1, minusLeft, x+1);
        
        // take the - path.
        s[x] = '-';
        valid += f(s, plusLeft, minusLeft-1, x+1);
    
    // no need to choose...
    } else
        valid += f(s, plusLeft, minusLeft, x+1);

    return valid;
};

int main () {

    // Read in
    string ok, meh; cin >> ok >> meh;

    int okPlus = 0, okMinus = 0, mehPlus = 0, mehMinus = 0, mehQ = 0, x;

    // count the -, +, and ?
    range(0, sz(ok), 1, x) {
        if (ok[x] == '+') okPlus++;
        else okMinus++;

        if (meh[x] == '+') mehPlus++;
        else if (meh[x] == '-') mehMinus++;
        else mehQ++;
    };

    // calculate the answer...
    printf("%.12lf\n", (double)f(meh, okPlus-mehPlus, okMinus-mehMinus, 0)/(1<<mehQ));

    return 0;
};