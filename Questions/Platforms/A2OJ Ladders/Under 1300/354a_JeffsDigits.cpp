#include <vector>
#include <iostream>
 
#define loop(s, e) for (int x = s; x < e; x++)
using namespace std;

/*


Check for the divisibility of 9 and then the divisibility of 10.

The divisibility of 9 can be found if the sum of all digits is divisible by 9.
The divisibility of 10 can be found if the number ends in 0.
If there is a number that is divisible by both 9 and 10, then it is divisible by 90
*/

int main () {

    int n, z = 0, currsum = 0;
    string currnum = "", max9div = "";
    cin >> n;

    // Read in all the digits
    loop(0, n) {
        char d; cin >> d;

        // If the digit is a 5, add 5 to the current sum and add a 5 to the currnum
        if (d == '5') {
            currnum.push_back(d);
            currsum += 5;
        
        // if the digit is a 0, increment zero count
        } else
            z++;

        // check for divisibility of 9 of the current sum of 5s.
        // if the current sum is divisible by 9, so 9 | sum
        if (currsum % 9 == 0)
            max9div = currnum;
    };

    // if there was no sum divisible by 9 found...
    if (max9div == "") {
        // if there are are no 0s and non divisible by 9, no answer.
        if (z == 0)
            cout << -1 << "\n";
        // if there are 0s, 90 divides 0
        else
            cout << 0 << "\n";
    } else {
        // the number is divisible by 9, but has no divisibility of 10 with no 0s.
        if (z == 0)
            cout << -1 << "\n";
        else {
            // there is a number than is divisible by both 9 and 10, therefore 90
            while (z > 0) {
                max9div.push_back('0');
                z--;
            };
            cout << max9div << "\n";
        };
    };

    return 0;
};