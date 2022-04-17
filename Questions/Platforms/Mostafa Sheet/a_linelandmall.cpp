#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;



int main () {

    int n; cin >> n;

    vector<int> cities(n);
    int x;
    range (0, cities.size(), 1, x)
        cin >> cities[x];

    range(0, cities.size(), 1, x) {
        if (x == 0) {
            cout << abs(cities[x+1]-cities[x]) << " " << abs(cities[x]-cities.back()) << "\n";
        } else if (x == n-1) {
            cout << abs(cities.back()-cities[x-1]) << " " << abs(cities.back()-cities[0]) << "\n";
        } else {
            int mini = min(abs(cities[x]-cities[x-1]), abs(cities[x]-cities[x+1])),
                maxi = max(abs(cities[x]-cities[0]), abs(cities[x]-cities.back()));
            cout << mini << " " << maxi << "\n";
        };

    };


}