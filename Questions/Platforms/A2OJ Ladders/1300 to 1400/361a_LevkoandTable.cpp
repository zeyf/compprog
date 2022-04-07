#include <bits/stdc++.h>
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*

Idea: Just go diagonally through the matrix and:

For all x, y in set(Z) (0 <= x <= y < n, matrix[x][y] = k)
Then, all rows have a sum of k, as do all columns by including k into every row, col axis intersection once.

*/

int main () {

    int n, k, x, y, z = 0; cin >> n >> k;
    vector<vector<int> > table(n, vector<int>(n, 0));

    range(0, n, 1, x) {
        table[x][z++] = k;
        range(0, n, 1, y) cout << table[x][y] << " ";
        cout << "\n";
    };

    return 0;
};