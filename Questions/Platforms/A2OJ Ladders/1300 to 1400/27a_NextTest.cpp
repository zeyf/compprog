#include <bits/stdc++.h>
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

int main () {

    set<int> seen;
    int n, m; cin >> n;
    m = n;

    while (m--) {
        int v; cin >> v;
        seen.insert(v);
    };

    int x, res=3001;
    range(1, 3001, 1, x) {
        if (!seen.count(x)) {
            res = x;
            break;
        };
    };

    cout << res << "\n";


    return 0;
};