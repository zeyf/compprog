#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

bool comp(pair<long long, long long> p1, pair<long long, long long> p2) {
    return p2.second > p1.second;
};

int main () {

    long long n, m; cin >> n >> m;
    vector<pair<long long, long long>  > containers(m, make_pair(0,0));
    long long x;

    range(0, m, 1, x) {
        cin >> containers[x].first >> containers[x].second;
    }

    sort(containers.begin(), containers.end(), comp);
    long long ans = 0;

    while (containers.size() > 0 && n > 0) {
        if (n >= containers.back().first) {
            ans += containers.back().first * containers.back().second;
            n -= containers.back().first;
        } else {
            ans += n * containers.back().second;
            n = 0;
        };
        containers.pop_back();
    };

    cout << ans << "\n";

    return 0;
};