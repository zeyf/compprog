#include <bits/stdc++.h>
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;


/*

I was thinking about creating sequences of prime numbers since
all prime numbers are coprime with each other, so using sieve of erasthosthenes came up and was my first approach.

However it proved to be too slow and considering the 100,000th prime number is 1299709, this sets a very high bound that may not ever be needed to be computed depending on the value of n

However, there is something I had not realized before but makes perfect sense... to get all coprime numbers n coprime numbers when n is bounded...

simply select a value such that there will consecutively be n coprime numbers.

Lets say n is 4.

Consider x, when x = n
Consider y, when y = 2*n

The interval from [n, 2n)

We know that n and 2n are not coprime, because the gcd(n, 2n) would simply be n.

Also we know that in the range [n, 2n] there are actually n+1 numbers.
Meaning that if we take a subset of [n, 2n], like [n, 2n-1], then we have n consecutive coprime numbers.

[4,5,6,7,8] --> n = 4, 2n = 8, count = 5
[4,5,6,7] --> n = 4, 2n-1 = 7, count 4.

For all a (where multiple is defined as a = by), such that (y > 1 ^ b > 1) ---> all values from [n, 2n-1] are coprime

It makes a ton of sense, but the seemingly trickiest questions can have the easiest answers...

*/

int main () {

    long long n, x, c = 0;
    cin >> n;
    range(200000, 300001, 1, x) {
        if (n == c) break;
        cout << x << " ";
        c++;
    };

    cout << "\n";
    return 0;
};