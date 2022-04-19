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

https://codeforces.com/contest/102/problem/B

*/

int main () {

    string s; cin >> s;
    if (s.size() == 1) {
        cout << 0 << "\n";
        return 0;
    }

    int count = 0;
    while (1) {
        long long sum = 0;
        while (s.size() > 0) {
            sum += s.back()-'0';
            s.pop_back();
        };

        count++;
        if (sum < 10) break;

        while (sum > 0) {
            s.push_back(48+(sum%10));
            sum /= 10;
        };
    }

    cout << count << "\n";

    return 0;

};