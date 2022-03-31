#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

#define loop(s, e) for (int x = s; x < e; x++)
using namespace std;

/*

Simple greedy counter strategy. First time using bitsets, just for fun.

*/

int main () {

    string n;
    cin >> n;
    bitset<100> bits(n);

    int count = 0, type = 0;
    loop(0, n.size()) {
        if (x == 0) {
            type = bits[x];
            count = 1;
        } else {
            if (bits[x] != type) {
                type = bits[x];
                count = 1;
            } else
                count++;
        };

        if (count == 7) break;
    };

    cout << (count == 7 ? "YES" : "NO") << "\n";

    return 0;
};