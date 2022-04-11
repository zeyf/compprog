#include <bits/stdc++.h>
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;


// character intervals!

bool comp(pair<char, pair<int, int> > a, pair<char, pair<int, int> > b) {
    return b.second.first > a.second.first;
};

int main () {

    map<char, pair<int, int> > charIntervals;
    string s; cin >> s;

    int x, y;
    range(0, s.size(), 1, x) {
        char c = s[x];
        if (!charIntervals.count(c)) {
            charIntervals[c] = make_pair(x, x);
        } else {
            charIntervals[c].second = x;
        };
    };

    map<char, pair<int, int> >::iterator itx = charIntervals.begin();
    vector<pair<char, pair<int, int> > > intervals;
    while (itx != charIntervals.end()) {
        intervals.push_back(make_pair((*itx).first, make_pair((*itx).second.first, (*itx).second.second)));
        itx++;
    };

    sort(intervals.begin(), intervals.end(), comp);

    int ans = 0;
    range(0, intervals.size(), 1, x) {
        pair<int, int> interval = intervals[x].second;
        if (interval.second-interval.first == 0)
            ans += intervals.size()-1-x;
        else {
            int len = (interval.second-1) - interval.first + 1;
            ans += ((len*(len+1))>>1) - len;
        }
    };

    return 0;
};