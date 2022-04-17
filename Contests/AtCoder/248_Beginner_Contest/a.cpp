#include <iostream>
#include <string>
#include <vector>
#include <set>

#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;


int main () {

    string s; cin >> s;
    vector<int> f(10, 0);

    int x; range(0, s.size(), 1, x) {
        f[s[x]-'0']++;
    };

    range(0, 10, 1, x) {
        if (!f[x])  {
            cout << x << "\n";
            return 0;
        }
    }


    return 0;
}