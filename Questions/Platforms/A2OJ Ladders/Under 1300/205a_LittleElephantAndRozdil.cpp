#include <bits/stdc++.h>
 
#define loop(s, e) for (int x = s; x < e; x++)
using namespace std;

/*

Tracked the minimum time and the count of a given minimum time.
If it was smaller, update.
If it was the same, increment.
Print time if unique, else Still Rodzil.
*/

int main () {

    long long n, min = 1e10, minCount = 1, minIdx = -1;
    cin >> n;

    loop(0, n) {
        int v; cin >> v;
        if (min > v) {
            minCount = 1;
            min = v;
            minIdx = x+1;
        } else if (min == v)
            minCount++;
    };

    if (minCount == 1)
        cout << minIdx << "\n";
    else
        cout << "Still Rozdil\n";

    return 0;
};