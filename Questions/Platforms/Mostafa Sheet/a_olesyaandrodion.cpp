#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;



int main () {

    int n, k; cin >> n >> k;

    if (n == 1) {
        if (k == 10) cout << -1 << "\n";
        else cout << k << "\n";
    } else {

        string ans = "";
        if (k != 10) {
            while (ans.size() < n)
                ans.push_back('0'+k);
        } else {
            ans.push_back('1');
            while (ans.size() < n) {
                ans.push_back('0');
            }
        }

        cout << ans << "\n";
    };


    return 0;
};