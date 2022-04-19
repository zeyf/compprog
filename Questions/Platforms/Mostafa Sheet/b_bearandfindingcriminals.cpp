#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;



int main () {

    int x, n, k; cin >> n >> k; vector<int> bcd(n);
    k -= 1;
    range(0, n, 1, x) cin >> bcd[x];
    
    int count = bcd[k];
    int a = k-1, b = k+1;
    while (a >= 0 || b < n) {
        if (a >= 0 && b < n) {
            if (bcd[a] == 1 && bcd[b] == 1) {
                count+=2;
            };
        } else if (a >= 0) {
            count += bcd[a];
        } else {
            count += bcd[b];
        };
        
        a -=1; b += 1;
    };

    cout << count << "\n";

    return 0;
};