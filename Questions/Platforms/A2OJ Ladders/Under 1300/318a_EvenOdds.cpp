#include <bits/stdc++.h>
 
#define loop(s, e) for (int x = s; x < e; x++)
using namespace std;

/*

Idea:
Came up with an O(1) mathematical approach. based on the relationship between k and n
Specifically, the fact that the sequence was even or odd was very relevant to the solution.
An odd length sequence from 1 to n is handled slightly differently than an even sequence.
In general, I used some discrete mathematic concepts to come up with this approach.
The definition of odd numbers as 2a+1 came up for all integers where k<=(n/2)
The answer for a given kth odd number came out to 2*(k-1) + 1
The answer for a given kth even number cases came out to:
2*(k-(n/2))

On odd length sequences, n was incremented by 1.

*/

int main () {
    long long n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << 1 << "\n";
        return 0;
    };

    if (n&1) n++;

    if (k <= (n>>1))
        cout << ((k-1)<<1)+1 << "\n";
    else
        cout << ((k-(n>>1))<<1) << "\n";

    return 0;
};