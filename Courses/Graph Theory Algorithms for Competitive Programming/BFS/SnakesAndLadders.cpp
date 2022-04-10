#include<bits/stdc++.h>
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*

Classic snakes and ladders.

Idea is simple:

Create a movement map to look up when going to enqueue a given position.

Then for each location, try all [1,6] dice throws and if they cause movement elsewhere, go to that location. Enqueue both if movement occurs.
Propagate distance.

*/

int min_dice_throws(int n, vector<pair<int, int> > &snakes, vector<pair<int, int> > &ladders) {
    if (n == 1) return 0;

    int x;
    map<int, int> moveMap;

    range(0, snakes.size(), 1, x) {
        pair<int, int> c = snakes[x];
        if (!moveMap.count(c.first)) moveMap[c.first] = c.second;
    };

    range(0, ladders.size(), 1, x) {
        pair<int, int> c = ladders[x];
        if (!moveMap.count(c.first)) moveMap[c.first] = c.second;
    };

    queue<pair<int, int> > q;
    set<int> visited;

    int start = moveMap.count(1) ? moveMap[1] : 1;
    if (start != 1) visited.insert(1);
    visited.insert(start);
    q.push(make_pair(start, 0));

    while (q.size() > 0) {
        pair<int, int> c = q.front();
        q.pop();

        range(1, 7, 1, x) {
            int nx = c.first+x;
            if (!visited.count(nx)) {
                if (nx == n)
                    return c.second+1;
                else if (nx > n)
                    break;
                if (moveMap.count(nx)) {
                    q.push(make_pair(moveMap[nx], c.second+1));
                    visited.insert(moveMap[nx]);
                    visited.insert(nx);
                } else {
                    q.push(make_pair(nx, c.second+1));
                    visited.insert(nx);
                };
            }
        };
    };

};