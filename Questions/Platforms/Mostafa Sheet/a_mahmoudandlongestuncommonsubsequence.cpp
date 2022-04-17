#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;



int main () {

    string a, b; cin >> a >> b;
    if (a.size() == b.size()) {
        if (a == b) cout << "-1" << "\n";
        else cout << a.size() << "\n";
    } else {
        cout << max(a.size(), b.size()) << "\n";
    };

    return 0;
};