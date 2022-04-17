#include <iostream>
#include <string>
#include <vector>
#include <set>

#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;


int main () {

    long long a, b, k; cin >> a >> b >> k;
    long long ans = 0;
    while (a < b) {
        a*=k;
        ans++;
    }

    cout << ans << "\n";

    return 0;
}