#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*

Link: https://codeforces.com/contest/680/problem/B

Topic: Adhoc / Two Pointers

Solution: Go outwards. Only if only one side is inbounds with a criminal or both are inbounds and both have criminals are you sure they are there.

*/

int main () {

    // read in
    int x, n, k; cin >> n >> k; vector<int> bcd(n);
    k -= 1;
    range(0, n, 1, x) cin >> bcd[x];
    
    // start count at whatever his city is! he will always know it's right or not.
    // Two pointers...
    int count = bcd[k];
    int a = k-1, b = k+1;

    // while all cities have not been visited...
    while (a >= 0 || b < n) {
        // if both are still valid options...
        if (a >= 0 && b < n) {
            // if both have criminals, no indecision, he knows they are there.
            if (bcd[a] == 1 && bcd[b] == 1) {
                count+=2;
            };
        
        // if only the left pointer is inbounds: answers only 1 or 0. Just keep adding, anything on that side is valid.
        } else if (a >= 0) {
            count += bcd[a];
        
        // implicit if (b>n) -- if only the right pointer is inbounds: answers only 1 or 0. Just keep adding, anything on that side is valid.
        } else {
            count += bcd[b];
        };

        // move pointers.
        a -=1; b += 1;
    };

    // print the total criminals he can for sure catch...
    cout << count << "\n";

    return 0;
};