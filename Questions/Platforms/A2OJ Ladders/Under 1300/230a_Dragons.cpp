#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
#define mp(a, b) make_pair(a, b)

/*

Idea:

Another greedy algorithm. This time, greedier than normal. Yes, sorting by the dragons strength in ascending order was done.
However on top of that search criteria, if multiple dragons have the same strength, sorting by bonus in descending order is better to have if damage occurred in battles.
However since this problem no damage is taken between battles, it actually doesnt matter if sorting by the second criteria, as if a dragon can overtake the first dragon of a given strength,
he can also over take the others, regardless of what their bonus is (even 0). If the problem was modified to damage per battle, then it is relevant.

*/

bool sortCriteria(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return b.first > a.first;
    else return a.second > b.second;
};

int main () {

    int s, n; cin >> s >> n;
    vector<pair<int, int> > dragons(n, mp(0, 0));

    int x;
    range(0, n, 1, x) cin >> dragons[x].first >> dragons[x].second;
    sort(dragons.begin(), dragons.end(), sortCriteria);

    range(0, n, 1, x) {
        pair<int, int> dragon = dragons[x];
        if (s <= dragon.first) {
            cout << "NO\n";
            return 0;
        };

        s += dragon.second;
    };

    cout << "YES\n";

    return 0;
};