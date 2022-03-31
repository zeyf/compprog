#include <bits/stdc++.h>
 
#define loop(s, e) for (int x = s; x < e; x++)
using namespace std;

/*

Idea:

Check if reverse is the same.

*/

int main () {

    string a, b; cin >> a >> b;
    if (a.size() != b.size()) cout << "NO\n";
    else {
        reverse(b.begin(), b.end());
        loop(0, b.size()) {
            if (a[x] != b[x]) {
                cout << "NO\n";
                return 0;
            };
        };
        cout << "YES\n";
    };



    return 0;
}