#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define range(startInc, endEx, step, var) for (var = startInc; step != 0 && step < 0 ? var > endEx : var < endEx; var += step)
#define mp(a, b) make_pair(a, b)

/*

Idea: very simple if checking.

*/

int main() {
    
    string s; cin >> s;
    int x;
    range(0, s.size(), 1, x) {
        if (s[x] == 'H' || s[x] == 'Q' || s[x] == '9') {
            cout << "YES\n";
            return 0;
        };
    };

    cout << "NO\n";

    return 0;
};