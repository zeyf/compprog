#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2) {
    return p2.second > p1.second;
}

int main () {

    int n; cin >> n;
    vector<pair<int, int> > f;
    int x;
    range(0, n, 1, x) {
        int u; cin >> u;
        f.push_back(make_pair(x+1, u));
    };

    sort(f.begin(), f.end(), comp);
    range(0, n, 1, x) {
        cout << f[x].first << " ";
    }

    cout << "\n";
    return 0;
};