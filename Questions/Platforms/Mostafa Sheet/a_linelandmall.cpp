#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*

Link: https://codeforces.com/contest/567/problem/A

Topic: Adhoc

Solution: Simple bound usage for minimum and maximums. Also logic since already sorted. Sorting

Time Complexity: O(N)
Space Complexity: O(N)

*/

int main () {

    // read in data
    int n; cin >> n;
    vector<int> cities(n);
    int x;
    range (0, cities.size(), 1, x)
        cin >> cities[x];

    // the furthest distance for 0th city is n-1th, and nearest 1st
    // the further for the n-1th city is the 0th, and nearest the n-2th
    // for an arbitrary non terminal xth city, the furthest is max of distance from 0th and n-1th city.
    // nearest for arbitrary non terminal xth city is min distance between x-1th and xth city, x and x+1th city.
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