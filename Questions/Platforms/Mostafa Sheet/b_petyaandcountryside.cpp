#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;



int main () {

    int n, x, mx = 0; cin >> n; vector<int> sections(n, 0);
    range(0, n, 1, x) cin >> sections[x];
    range(0, n, 1, x) {
        int count = 1, y1 = x-1, y2 = x+1;
        range(y1, -1, -1, y1) {
            if (sections[y1] > sections[y1+1]) break;
            count++;
        };
        
        range(y2, n, 1, y2) {
            if (sections[y2] > sections[y2-1]) break;
            count++;
        };

        mx = max(mx, count);
    };

    cout << mx << "\n";

    return 0;
};