#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

int ub(vector<int> &a, int x) {
    int low = 0, high = a.size()-1;

    int best = -10e7;
    while (low <= high) {
        int mid = low + ((high-low)>>1);
        if (a[mid] > x)
            best = a[mid], high = mid-1;
        else
            low = mid+1;
    };

    return best;
};

int lb(vector<int> &a, int x) {
    int low = 0, high = a.size()-1;

    int best = -10e7;
    while (low <= high) {
        int mid = low + ((high-low)>>1);
        if (a[mid] >= x) {
            best = a[mid];
            high = mid-1;
        } else
            low = mid+1;
    };

    return best;
};



int main () {

    int tc; cin >> tc;
    while (tc--) {
        int n, value; cin >> n >> value;
        vector<int> a(n);
        int x;
        range(0, n, 1, x)
            cin >> a[x];
        sort(a.begin(), a.end());
        int ans = lb(a, value);
        if (ans == (int)-10e7)
            cout << "Not found!\n";
        else
            cout << "Answer:\t" << ans << "\n";
    }


    return 0;
};