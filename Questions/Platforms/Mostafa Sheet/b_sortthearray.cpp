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
typedef set<char> sc;

/*
VECTOR TYPEDEFS
*/

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pii > vpii;
typedef vector<char > vc;

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

Link: https://codeforces.com/contest/451/problem/B

Topic: Sorting

Solution: Mark all decreasing segments. If more than 1 segment, no. If only one: reverse it, check if this sorts array. if not, no, else yes.

Time Complexity: O(NLogN)
Space Complexity: O(N)

*/

int main () {

    // Read in input
    int n, x, y; cin >> n;

    // Read in numbers. Created an array to mark all decreasing segments, using constraint of positive to my advantage.
    vll a(n), b(n);
    range(0, n, 1, x) {
        cin >> a[x];
        b[x] = a[x];
        if (x>0 && a[x-1]>a[x]) {
            if (b[x-1] > 0)
                b[x-1]*=-1;
            b[x]*=-1;
        };
    };

    int decseg = 0, decseglow = -1, decseghigh = -1;

    // iterate thorugh the values array
    x = 0;
    while (x < n) {
        y = x;
        // if we found a decreasing segment...
        if (b[y] < 0) {

            // increment decreasing segment counter
            decseg++;
            // iterate forward until end of array or end of decreasing segment (increasing)
            while (y < n && b[y] < 0)
                y++;

            // store the interval indexes and update x
            decseglow = x+1;
            decseghigh = y;
            x=y;
        } else
            x++;
    };

    // if no decreasing, then any index reverse is good.
    if (decseg == 0) {
        cout << "yes\n1 1\n";
    // if there's one decreasing segment...
    } else if (decseg == 1) {

        // reverse the decreasing segment
        bool isSorted = true;
        int x = decseglow-1, y = decseghigh-1;
        while (x < y) {
            int t = a[x];
            a[x] = a[y];
            a[y] = t;
            x++; y--;
        };

        // check if after reversal the array is sorted
        y = 1;
        while (y < n && isSorted) {
            if (a[y-1]>a[y]) isSorted = false;
            y++;
        }

        // if it is sorted after segment reverse, print reversable segment
        if (isSorted)
            cout << "yes\n" << decseglow << " " << decseghigh << "\n";
        else // else no, it doesnt sort if you flip the dec seg
            cout << "no\n";
    } else // theres more than one decreasing segment. one reverse still doesnt sort.
        cout << "no\n";



    return 0;
};