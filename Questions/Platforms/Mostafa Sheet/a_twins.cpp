#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

int main () {

    int n; cin >> n;
    vector<int> coins(n);
    long long total = 0;
    int x; range(0, n, 1, x) {
        cin >> coins[x];
        total += coins[x];
    };
    sort(coins.begin(), coins.end());
    int ans = 0;
    while (coins.size() > 0 && ans <= total) {
        ans += coins.back();
        total -= coins.back();
        coins.pop_back();
    };

    cout << n-coins.size() << "\n";

    return 0;
};