#include <bits/stdc++.h>
 
#define loop(s, e) for (int x = s; x < e; x++)
using namespace std;

/*

Idea:

Found the relationship between 3 numbers in construction of fibonacci numbers.
For any given nth fibonacci number such that n >= 4 (1 indexed)
Three numbers that add up to that F(n) are...

F(n) = F(n-4) + F(n-3) + F(n-1);

This is because:
F(n-2) = F(n-4) + F(n-3),
and...
F(n) = F(n-2) + F(n-1)

So by substitution,

F(n) = (F(n-4) + F(n-3)) + F(n-1)
F(n) = F(n-4) + Fn-3) + F(n-1) for all N such that N >= 4 (1 indexed)


*/

int main () {

    int n; cin >> n;

    if (n == 0)
        cout << "0 0 0\n";
    else if (n == 1)
        cout << "0 0 1\n";
    else if (n == 2)
        cout << "0 1 1\n";
    else if (n == 3)
        cout << "1 1 1\n";
    else {
        vector<int> dp(2, 1);
        int x = 2;
        // guaranteed to be a fibonacci number.
        while (dp[x-2]+dp[x-1] != n) {
            dp.push_back(dp[x-2]+dp[x-1]);
            x++;
        };

        cout << dp[x-4] << " " << dp[x-3] << " " << dp[x-1] << "\n";
    };

};