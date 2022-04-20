#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*

Link: https://codeforces.com/contest/136/problem/A

Topic: Sorting

Solution: Sorted by index of who they got a gift from.

Time Complexity: O(NlogN)
Space Complexity: O(N)

*/

// comparison function. ascending.
bool comp(pair<int, int> p1, pair<int, int> p2) {
    return p2.second > p1.second;
}

int main () {

    // read in data
    int n; cin >> n;
    vector<pair<int, int> > f;
    int x;
    range(0, n, 1, x) {
        int u; cin >> u;
        // store the relationship as a pair, of the index and who was given a present.
        f.push_back(make_pair(x+1, u));
    };

    // sort by the second pair value to get the order ascending by index who was given an ith present
    sort(f.begin(), f.end(), comp);

    // print answer
    range(0, n, 1, x) {
        cout << f[x].first << " ";
    }

    cout << "\n";
    return 0;
};