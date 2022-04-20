#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*

Link: https://codeforces.com/contest/16/problem/B

Topic: Greedy / Sorting

Solution: Sort containers by the number of matchboxes. Take the best n match boxes.

Time Complexity: O(NlogN)
Space Complexity: O(N)

*/

// comparison function... maximizes matches per box over box count.
bool comp(pair<long long, long long> p1, pair<long long, long long> p2) {
    return p2.second > p1.second;
};

int main () {

    // read in data
    long long n, m; cin >> n >> m;
    vector<pair<long long, long long>  > containers(m, make_pair(0,0));
    long long x;

    range(0, m, 1, x) {
        cin >> containers[x].first >> containers[x].second;
    }

    // sort the containers by matches per matchbox.
    sort(containers.begin(), containers.end(), comp);
    long long ans = 0;

    // while there are containers left and n > 0...
    while (containers.size() > 0 && n > 0) {
        // if we can take all of them...
        if (n >= containers.back().first) {
            ans += containers.back().first * containers.back().second;
            n -= containers.back().first;
        
        // if we can only take some of them...
        } else {
            ans += n * containers.back().second;
            n = 0;
        };

        // remove the current container.
        containers.pop_back();
    };

    // print answer
    cout << ans << "\n";

    return 0;
};