#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*

Link: https://codeforces.com/contest/584/problem/A

Topic: Number Theory / Divisibility

Solution: Divisibility tricks for single digits and 10.

Time Complexity: O(N), best O(1)
Space Complexity: O(N), best O(1)
*/

int main () {

    // read in
    int n, k; cin >> n >> k;

    // if number is only 1 digit long
    if (n == 1) {
        // no leading 0s. Meaning 0 is not option. So, 10 does not divide any other one digit number.
        if (k == 10) cout << -1 << "\n";
        // any single digit divisor from 2<=k<=9 divides itself...
        else cout << k << "\n";
    } else {
        
        string ans = "";

        // divisor is in range 2<=k<=9
        if (k != 10) {
            // create a number composing only of n digits of k.
            while (ans.size() < n)
                ans.push_back('0'+k);
        
        // divisibility of ten -- as long as number ends with 0. Add 1, pad with n-1 0s.
        } else {
            ans.push_back('1');
            while (ans.size() < n) {
                ans.push_back('0');
            }
        }

        // print answer
        cout << ans << "\n";
    };


    return 0;
};