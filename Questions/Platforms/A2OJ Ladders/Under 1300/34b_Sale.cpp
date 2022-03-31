#include <iostream>
#include <vector>
#include <algorithm>

#define loop(s, e) for (int x = s; x < e; x++)
using namespace std;

/*

Idea:

A greedy approach. He will only ever get paid when tv sets are negative.
By sorting, we get an optimal substructure (the min most value of the rest of the list)
So, while i < m when and the sets[i] < 0 (we can gain money), keep getting more tv sets.

*/

int main () {

    int n, m; cin >> n >> m;
    vector<int> sets(n);
    loop(0, n) cin >> sets[x];
    sort(sets.begin(), sets.end());

    int i = 0, sum = 0;
    while (i < m && sets[i] < 0) sum += sets[i++];
    cout << sum*-1 << "\n";

    return 0;

};