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

Link: https://codeforces.com/contest/102/problem/B

Topic: Math / Logic?

Solution: Break down number until 1 digit or digit sum length == 1.

Time Complexity: O(kLogS) where k is number of iterations to get to 1 digit.
Space Complexity: O(1)

*/

int main () {

    // read in
    string s; cin >> s;
    
    // if one digit... stop.
    if (s.size() == 1) {
        cout << 0 << "\n";
        return 0;
    }

    // keep going while greater than 9...
    int count = 0;
    while (1) {

        // break down and sum number
        long long sum = 0;
        while (s.size() > 0) {
            sum += s.back()-'0';
            s.pop_back();
        };

        // count, and basecase...
        count++;
        if (sum < 10) break;

        // build number back up
        while (sum > 0) {
            s.push_back(48+(sum%10));
            sum /= 10;
        };
    }

    // print answer
    cout << count << "\n";

    return 0;

};