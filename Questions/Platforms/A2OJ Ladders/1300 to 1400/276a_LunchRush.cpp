#include <bits/stdc++.h>
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*

Idea: basic max greedy.

*/

int main () {

    long long n, k; cin >> n >> k;
    long long x;
    long long res = (-1)*(1<<30);
    range(0, n, 1, x) {
        long long f, t; cin >> f >> t;
        if (t > k) res = max(res, f-(t-k));
        else res = max(res, f);
    };

    cout << res << "\n";

    return 0;
}