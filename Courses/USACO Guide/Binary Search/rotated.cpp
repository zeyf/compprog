#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

int rotatedSearch(vector<int> &a) {
    int low = 0, high = a.size()-1;

    int best = -10e7;
    while (low <= high) {
        int mid = low + ((high-low)>>1);

        /*
            since we are in a rotated array, we know that if we have a value lesser than
            the current mid to our far left, it cannot be the smallest value in the sequence.
            we know that it will be towards our right.
        */
        if (a[mid] >= a[0]) {
            low = mid+1;
        } else {
            best = a[mid];
            high = mid-1;
        };

    };

    return best;
};



int main () {

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        vector<int> a(n);
        int x;
        range(0, n, 1, x)
            cin >> a[x];

        int ans = rotatedSearch(a);
        if (ans == (int)-10e7)
            cout << "Not found!\n";
        else
            cout << "Answer:\t" << ans << "\n";
    }


    return 0;
};