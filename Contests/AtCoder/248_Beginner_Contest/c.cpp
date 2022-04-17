#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>


#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;


vector<int> dice;
map<int, int> dp;


int f(int n, int m, int k) {
    if (k < 0) return 0;
    else if (dp.count(k)) return dp[k];
    else if (n == 0) {
        return dp[k] = 1;
    }
    int x; range(m, 0, -1, x) {
        dp[k] += f(n-1,m,k-x) % 998244353;
    };

    return dp[k] % 998244353;
};

int main () {

    int n, m, k; cin >> n >> m >> k;

    int x; range(0, 7, 1, x) {
        dice.push_back(x);
    };

    dp[0] = 1;

    cout << f(n, m, k) << "\n";

    return 0;
}