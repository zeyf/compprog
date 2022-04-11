#include <bits/stdc++.h>
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

int main () {

    int n; cin >> n;

    set<int> values;
    int c = n, mini = 1e8, maxi = -1;
    while (c--) {
        int v; cin >> v;
        values.insert(v);
        mini = min(mini, v);
        maxi = max(maxi, v);
    };

    int x;
    bool good = true;
    range(1, maxi+1, 1, x) {
        if (!values.count(x)) {
            cout << x << "\n";
            good = false;
        };
    };

    if (good)
        cout << "good job\n";

    return 0;
};