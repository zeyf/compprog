#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;
typedef pair<int, int> pii;
#define f first
#define s second

/*

Pretty much a derangement of a permutation of integers, however involved swapping values.

*/

#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
#define mp(a, b) make_pair(a, b)

int main () {

    int n; cin >> n;
    if (n&1) cout << "-1\n";
    else {
        int x;
        range(1, n, 2, x)
            cout << x+1 << " " << x << " ";
        cout << "\n";
    };

    return 0;
}