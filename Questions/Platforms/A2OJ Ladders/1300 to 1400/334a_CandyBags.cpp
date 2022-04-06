#include <bits/stdc++.h>
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*

Idea: all pairs that will sum to the same for all brothers can be found by incrementing lowbound and decrementing highbound.

*/

int main () {

    int n; cin >> n;
    int t = n;
    int low = 1, high = n*n;
    while (t > 0) {
        int j = n;
        while (j > 0) {
            cout << low << " " << high << " ";
            low++;
            high--;
            j -= 2;
        };
        cout << "\n";
        t--;
    };

    return 0;
}