#include <bits/stdc++.h>
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*

Idea/Intuition:

This was taken on a by case basis in terms of logical reasoning:

Case #1: All 1s
    - If they are all 1s, it doesn't matter which you delete
Case #2: All 0s
    - If they are all 0s, it doesn't matter which you delete
Case #3: Has 1s and 0s
    - It comes down to some simple math and binary knowledge.
        - Since a 0 bit composed "less" to the overall decimal value the binary represents, we want to delete one 0 value from the bit string.
            - Then it comes down to a question of which 0 do we delete?
            - Given a bit string 10110, which represents 22, if you delete the lowest 0 bit, meaning the right most, you get:
                1011, which is 11 in decimal. Meanwhile if you delete the left most bit (the highest 0 bit), you get 1110, which is: 14.
                This is because by prioritizing the highest (left most) 0 bit to delete, you only divide a segment of the overall summation that binary represents by half.
                Meanwhile by deleting the lowest (right most) 0 bit, you maximize the summation over which you are dividing by two, resulting in a smaller sum than the former approach.

*/

int main () {

    // read in the bit string
    string bitstring, res; cin >> bitstring;

    // counters and boolean for if the first zero has been found
    int ones = 0, zeros = 0;
    bool zeroFound = false;

    // iterate over the string

    int x;
    range(0, bitstring.size(), 1, x) {
        if (bitstring[x] == '1') {
            ones++;
            res.push_back('1');
        } else {
            zeros++;
            if (!zeroFound) {
                zeroFound = true;
            } else {
                res.push_back('0');
            };
        };
    };

    if (ones == bitstring.size() || zeros == bitstring.size())
        cout << res.substr(0, bitstring.size()-1) << "\n";
    else
        cout << res << "\n";

    return 0;
};