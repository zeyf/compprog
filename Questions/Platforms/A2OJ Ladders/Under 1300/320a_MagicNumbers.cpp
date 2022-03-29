#include <iostream>
#include <vector>

#define loop(s, e) for (int x = s; x < e; x++)
using namespace std;

/*

Idea:

Recursive combinations with backtracking / pruning.

By trying the longest values first, with the array set up at:
{ 144, 11, 1 }, this will cut down on many calls.

For example, if the sequence is 1111111111

it can be built the following ways:

11 11 11 11 11 (5 recursive calls)

or

1 1 1 1 1 1 1 1 1 1 (10 recursive calls)


Also, by pruning the search such that adding a combination choice is less or equal to the size of the goal number,
we can cut out paths and recursive calls we don't need to consider.

Also, checking if the combination matches the rest of the goal string for the size of the current option also prunes the search.


*/

bool isMatch(string goal, string combo, int k) {
    int i = 0;
    loop(k, k+combo.size())
        if (goal[x] != combo[i++]) return false;
    return true;
};

bool combo(string seq, vector<string> &options, string goal) {
    if (seq.size() == goal.size()) return true;

    loop(0, options.size())
        if (seq.size()+options[x].size() <= goal.size() && isMatch(goal, options[x], seq.size()))
            if (combo(seq+options[x], options, goal)) return true;
    return false;
};

int main () {

    string n; cin >> n;
    vector<string> options(3, "");
    options[0] = "144"; options[1] = "14"; options[2] = "1";
    if (combo("", options, n)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
};