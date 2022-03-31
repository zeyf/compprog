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

Idea:

Pretty much checking if "hello" is a subsequence of a given string.

*/

int main () {
    string s; cin >> s;
    string hello = "hello";
    int x, y = 0;
    range(0, s.size(), 1, x)
        if (s[x] == hello[y]) y++;

    cout << (y == hello.size() ? "YES" : "NO") << "\n";
};