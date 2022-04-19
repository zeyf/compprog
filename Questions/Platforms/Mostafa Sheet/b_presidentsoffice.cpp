#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*DEFINES*/

#define pushb push_back
#define popb pop_back
#define ins insert
#define co count
#define sorter(a, comp) sort(a.begin(), a.end(), comp)
#define sz(a) sz.size()


/*
TYPEDEFS
*/

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pllll;

/*
SET TYPEDEFS
*/

typedef set<int> si;
typedef set<ll> sll;
typedef set<string> ss;
typedef set<pii > spii;
typedef set<pllll > spllll;
typedef set<char> sc;

/*
VECTOR TYPEDEFS
*/

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pii > vpii;
typedef vector<char > vc;

/*
MAP TYPEDEFS
*/

typedef map<int, int> mii;
typedef map<ll, ll> mllll;
typedef map<string, int> msi;
typedef map<char, int> mci;
typedef map<int, vi > mivi;
typedef map<string, vs > msvs;

/*

https://codeforces.com/contest/6/problem/B

*/

int main () {

    // Read in input data
    int n, m; char president; cin >> n >> m >> president;

    // initialize the board and the visited set
    vector<vc > board(n, vc(m, '.'));
    spii presidentDesk;

    // read in the board...
    int x, y;
    range(0, n, 1, x) {
        range(0, m, 1, y) {
            cin >> board[x][y];
            // if we find part of the president's desk, add it to the set
            if (board[x][y] == president) {
                presidentDesk.ins(make_pair(x, y));
            };
        };
    };

    // initialize the seenDeputies, to store only unique ones found.
    sc seenDeputies;
    // Since deputies desks are ADJACENT, this can only happen if they are immediately above, down, left, or right
    int dr[] = { -1,0,0,1 }, dc[] = { 0,-1,1,0 };
 
    // Iterate through all coordinates of the president's desk... really this is done for the edges...
    auto it = presidentDesk.begin();
    while (it != presidentDesk.end()) {
        // try all possible valid directions that qualify "adjacent"
        range(0, 4, 1, x) {
            // check if the next row and next column are inbounds, non empty cells, and not the president...
            int nr = it->first+dr[x], nc = it->second+dc[x];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] != '.' && board[nr][nc] != president) {
                // if a deputy, insert their character into deputy set... only uniques will be.
                seenDeputies.ins(board[nr][nc]);
            };

        }

        it++;
    }

    // the number of deputies with desks that touch the president's desk.
    cout << seenDeputies.size() << "\n";

    return 0;
};