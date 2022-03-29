#include <iostream>
#include <vector>

#define loop(s, e) for (int x = s; x < e; x++)
using namespace std;

/*

Idea:
Considering the constraints, a bruteforce is good//fast enough.
Track maximums and their counts.

*/

int main () {

    int n, m;
    
    cin >> n;
    vector<int> pedalAxles(n), rearWheelAxles;
    loop(0, n) cin >> pedalAxles[x];

    cin >> m;
    rearWheelAxles = vector<int>(m);
    loop(0, m) cin >> rearWheelAxles[x];

    int maxRatio = 0, maxRatioCount = 0, i = 0, j;
    while (i < n) {
        j = 0;
        while (j < m) {
            int b_j = rearWheelAxles[j], a_i = pedalAxles[i];
            if (b_j % a_i == 0) {
                int div = b_j/a_i;
                if (div > maxRatio) {
                    maxRatioCount = 1;
                    maxRatio = div;
                } else if (div == maxRatio)
                    maxRatioCount++;
            };

            j++;
        };

        i++;
    };

    cout << maxRatioCount << "\n";

    return 0;
};