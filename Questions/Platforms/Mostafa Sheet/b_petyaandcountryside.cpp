#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*

Link: https://codeforces.com/contest/66/problem/B

Topic: Bruteforce

Solution: Considering the very small constraints, this was bruteforceable.

*/

int main () {

    // read in the data...
    int n, x, mx = 0; cin >> n; vector<int> sections(n, 0);
    range(0, n, 1, x) cin >> sections[x];

    // brute force.
    range(0, n, 1, x) {
        int count = 1, y1 = x-1, y2 = x+1;
        
        // check leftwards of x, and constantly compare current to previous...
        range(y1, -1, -1, y1) {
            if (sections[y1] > sections[y1+1]) break;
            count++;
        };

        // check rightwards off x, and constantly compare current to previous...
        range(y2, n, 1, y2) {
            if (sections[y2] > sections[y2-1]) break;
            count++;
        };

        // compare current flow to max.
        mx = max(mx, count);
    };

    // print the answer.
    cout << mx << "\n";

    return 0;
};