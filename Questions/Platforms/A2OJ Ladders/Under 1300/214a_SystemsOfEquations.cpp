#include <iostream>
#include <vector>
#include <algorithm>

#define loop(s, e) for (int x = s; x < e; x++)
using namespace std;

/*

Idea:

Bruteforce for the equations. The constraints of n and m allow for it.

*/

int main () {

    int n, m; cin >> n >> m;

    int a = 0, count = 0;

    while (a < 1001) {
        int b = 0;
        while (b < 1001) {
            if (a*a+b == n && a+b*b == m) count++;

            b++;
        };

        a++;
    };

    cout << count << "\n";

    return 0;
};