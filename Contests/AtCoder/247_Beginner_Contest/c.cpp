#include <iostream>
#include <string>
#include <map>
#include <vector>

#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*

Known: S_1 = "1"

The recurrence relation: S(n-1) + S(n-1) + c

The design of the recurrence result was: S(n-1) + n + S(n-1)

The following recurrence relation corresponds:

T(n) = 2T(n-1) + n
T(1) = 1;


To solve:

T(n-1) = 2T(n-2) + (n-1)
T(n-2) = 2T(n-3) + (n-2)
T(n-3) = 2T(n-4) + (n-3)

T(n) = 2( 2T(n-2) + (n-1) ) + n
T(n) = 4T(n-2) + 2n + n - 2
T(n) = 4(2T(n-3) + (n-2)) + 2n + n - 2
T(n) = 8T(n-3) + 4n + 2n + n + - 8 - 2
T(n) = 8(2T(n-4) + (n-3)) + 4n + 2n + n + - 8 - 2
T(n) = 16T(n-4) + 8n + 4n + 2n - 24 - 8 - 2
T(n) = 16T(n-4) + 15n - 34
T(n) = 16T(n-4) + 15n

General Form:

T(n) = (2^k)T(n-k)+(2^(k-1))n
n - k = 1;
n = k - 1;
k = n - 1;

T(n) = 2^(n-1) + n2^(n-2)
T(n) = ( (2^(-1)) (2^(n)) ) + n( (2^(-2)) (2^(n)) )
T(n) = (2^n) + n(2^n)
O(n) = n(2^n)

However, we can do better. We can actually do O(n).

Using DP to store previous results.

*/


/* ITERATIVE TABLE APPROACH */
int main () {

    int n, x; cin >> n;
    vector<string> dp(n+1);
    dp[1] = "1";

    range(2, n+1, 1, x)
        dp[x] = dp[x-1] + " " + to_string(x) + " " + dp[x-1];
    cout << dp[n] << "\n";

    return 0;
};


/* INITIAL RECURSIVE MEMOIZATION APPROACH */

// string rec(int n, map<int, string> &memo) {
//     if (n==1) return "1";
//     else if (memo.count(n)) return memo[n];
//     return memo[n] = rec(n-1, memo) + " " + to_string(n) + " " + rec(n-1, memo);
// };

// int main () {

//     int n; cin >> n;
//     map<int, string> memo;
//     cout << rec(n, memo) << "\n";

//     return 0;
// }