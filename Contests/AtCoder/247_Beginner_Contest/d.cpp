#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>

#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pllll;

/*

This problem and "solution" I coded up in the last minute of the contest. I had also started it in the last minute, so it was absolute shit.
However, I took a look at the editorial, and it taught me a useful technique and observation...

Considering everytime I am adding to the array I am adding the value c a total of x times, instead of performing x additions onto the deque,
I can just make one addition and simply store the count and value information in a pair. This

Then, when it's time to remove y values, all I have to do is check the count of the frontmost value. It is a pair { c, x }...
While y > 0, pop off values for good if y-x >= 0. If y is then 0, stop. If y-x < 0, then we must do some simple math...

add y*c to the value, and decrement c at the pair at the front of the deque. THis will require a pop and re push to the front.

*/


/*WORK IN PROGRESS*/
int main () {

    int q; cin >> q;
    deque<pllll> cylinder;

    ll sum = 0;

    while (q--) {
        int type; cin >> type;
        if (type == 1) { // add
            ll x, c; cin >> x >> c;
            cylinder.push_back(make_pair(c, x));
        } else { // remove
            ll y, sum = 0; cin >> y;

            while (y > 0) {
                pllll front = cylinder.front();
                if (y - front.second >= 0) {
                    sum += front.second*front.first;
                    y -= front.second;
                    cylinder.pop_front();
                } else {
                    sum += y*front.first;
                    cylinder.pop_front();
                    cylinder.push_front(make_pair(front.first, front.second-y));
                    y = 0;
                };
            };

            cout << sum << "\n";

        };
    };


    return 0;
}



// int main () {

//     deque<long long> cylinder;

//     int q;  cin >> q;

//     while (q--) {
//         int type; cin >> type;
//         if (type == 1) {
//             long long x, c;  cin >> x >> c;
//             while (c--) {
//                 cylinder.push_back(x);
//             }
//         } else {
//             long long c; cin >> c;
//             long long sum = 0;
//             while (c--) {
//                 sum += cylinder.front();
//                 cylinder.pop_front();
//             };
            
//             cout << sum << "\n";
//         };
//     };

//     return 0;
// }