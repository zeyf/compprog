#include <bits/stdc++.h>
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*

Idea:

Sum all of them, for every data point check if the exclusion of it from the sum is even. if so, increment.

*/

int main () {

    int n; cin >> n;
    vector<int> bags(n);
    
    int sum = 0, x;
    range(0, n, 1, x) {
        cin >> bags[x];
        sum += bags[x];
    };

    int res = 0;
    range(0, n, 1, x)
        if (((sum-bags[x]) & 1) == 0) res++;

    cout << res << "\n";

    return 0;
}