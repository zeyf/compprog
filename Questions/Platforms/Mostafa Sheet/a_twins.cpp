#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*

Link: https://codeforces.com/contest/160/problem/A

Topic: Greedy / Sorting

Solution: Greedy by sorting the coins. When you cut down the initial total and take more than there's left, stop.

Time Complexity: O(NlogN)
Space Complexity: O(N)

*/

int main () {

    // read in
    int n; cin >> n;
    vector<int> coins(n);
    long long total = 0;
    int x; range(0, n, 1, x) {
        cin >> coins[x];
        total += coins[x];
    };

    // sort
    sort(coins.begin(), coins.end());
    
    // take coins while you have less or equal than what is left.
    int ans = 0;
    while (coins.size() > 0 && ans <= total) {
        ans += coins.back();
        total -= coins.back();
        coins.pop_back();
    };

    // print number of coins taken...
    cout << n-coins.size() << "\n";

    return 0;
};