#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

#define uloop(s, e) for (int x = s; x < e; x++)
#define dloop(s, e) for (int x = s; x > e; x--)

using namespace std;

/*

Idea:

Notice how the only element that fully changes side is the the one where x = 1, so the first element.
The others just shift to the left by one.
Therefore, print the last element (n) first, then the rest from [1, n)

*/

int main () {

    int n; cin >> n;

    cout << n << " ";
    uloop(1, n) cout << x << " ";

    return 0;
};