#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;
typedef pair<int, int> pii;
#define f first
#define s second

#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
#define mp(a, b) make_pair(a, b)

/*

Greedy approach.
I realize that I was heavily overthinking this one for some reason... I am working on this.

*/

int main () {
    int n, x, y, res = 0, left = 0, right = 0; cin >> n;

    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &x, &y);
        left += x;
        right += y;
    }
    printf("%d\n", min(left, n - left) + min(right, n - right));

};