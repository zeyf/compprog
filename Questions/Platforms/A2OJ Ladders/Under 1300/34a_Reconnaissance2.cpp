#include <bits/stdc++.h>
 
#define loop(s, e) for (int x = s; x < e; x++)
using namespace std;

/*

Idea:

Store the initial soldier height. Then maintain a previous variable that updates at each soldier.
Compare the height of the current soldier to that of the previous soldier.
if this difference in height is minimal relative to all soldier pairs seen so far, update it, and keep track of the low index and high Index.
Then, since soldiers are standing in a circle, the first and last soldier can be neighbors as well.
Compare the abs of the initial with that of the previous, which would sit at the last soldier at the end.
If their abs difference is smaller than that of the regular comparisons of neighboring height minimal, then print their indexes,
else print the lowerI and higherJ soldier indexes.

*/

int main () {

    int n; cin >> n;

    int initial, prev, lowerI, higherJ, minHeightDiff = 1e8;

    loop(0, n) {
        int v; cin >> v;
        if (x != 0) {
            if (minHeightDiff > abs(v-prev)) {
                lowerI = x;
                higherJ = x+1;
                minHeightDiff = abs(v-prev);
            };
            prev = v;
        } else
            initial = prev = v;

    };

    if (minHeightDiff > abs(initial-prev))
        cout << n << " " << 1 << "\n";
    else
        cout << lowerI << " " << higherJ << "\n";

    return 0;

};