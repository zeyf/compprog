#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*

Link: https://codeforces.com/problemset/problem/766/A

Topic: Adhoc / Strings

Solution: Simple observation.

Time Complexity: O(1)
Space Complexity: O(1)

*/

int main () {

    // read in strings
    string a, b; cin >> a >> b;

    // if same, no difference.
    if (a==b) cout << "-1\n";
    // else return longest string length between the two.
    else cout << max(a.size(), b.size()) << "\n";

    return 0;
};