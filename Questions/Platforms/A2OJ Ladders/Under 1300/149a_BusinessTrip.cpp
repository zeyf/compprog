#include <iostream>
#include <vector>
#include <algorithm>

#define loop(s, e) for (int x = s; x < e; x++)
using namespace std;

/*

Idea:

Greedy approach. Sort the sizes, start from the end while plant is not at least k long.

*/

int main () {

    int k; cin >> k;
    if (k == 0) { cout << "0\n"; return 0; };
    vector<int> sizes(12);
    loop(0, 12) cin >> sizes[x];
    sort(sizes.begin(), sizes.end());
    int i = 12;
    while (k > 0 && i > 0) {
        k -= sizes[i-1];
        i--;
    };

    if (k <= 0)
        cout << 12-i << "\n";
    else if (k > 0)
        cout << -1 << "\n";

    return 0;
}