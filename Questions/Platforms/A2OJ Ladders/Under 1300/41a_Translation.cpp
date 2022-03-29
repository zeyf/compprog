#include <bits/stdc++.h>
 
#define loop(s, e) for (int x = s; x < e; x++)
using namespace std;


int main () {

    string a, b; cin >> a >> b;
    if (a.size() != b.size()) cout << "NO\n";
    else {
        reverse(b.begin(), b.end());
        int y = b.size()-1;
        loop(0, b.size()) {
            if (y >= x) break;
            if (a[x] != b[y]) {
                cout << "NO\n";
                return 0;
            };
            y--;
        };
        cout << "YES\n";
    };



    return 0;
}