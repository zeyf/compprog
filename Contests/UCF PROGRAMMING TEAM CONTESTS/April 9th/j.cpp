#include <bits/stdc++.h>
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

int main () {

    int n; cin >> n;
    long long maxi = -1e8;

    vector<long long> cards;
    int x;

    range(0, n, 1, x) {
        long long v; cin >> v;
        maxi = max(maxi, v);
        cards.push_back(v);
    };

    double maxAverage = -1e9;
    long long runningSum = 0;
    range(n-1, -1, -1, x) {
        long long cc = cards[x];
        runningSum += cc;
        maxAverage = max(maxAverage, (double)runningSum/(n-x));
    };

    double best = max(maxAverage, (double)maxi);

    if (best <= 0) best = 0;
    printf("%.9lf\n", best);

};