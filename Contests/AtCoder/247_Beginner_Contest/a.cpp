#include <iostream>
#include <string>

#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*

This resembled right shifting in binary but with a binary string.
Simply take all characters from [0, n-2] and replace [1,n-1] with them, and set [0] to "0", like padding does in binary when shifting.

*/
int main () {

    string s; cin >> s;
    int x;
    string res;
    range(0, 3, 1, x) res.push_back(s[x]);
    cout << "0"+res << "\n";

    return 0;
}