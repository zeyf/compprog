#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*DEFINES*/

#define add push_back
#define rem pop_back
#define ins insert
#define co count
#define fi first
#define se second
#define sorter(a, comp) sort(a.begin(), a.end(), comp)
#define sz(a) a.size()
#define nl << "\n"
#define cnl cout << "\n"


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

/*
VECTOR TYPEDEFS
*/

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pii > vpii;

/*
MAP TYPEDEFS
*/

typedef map<int, int> mii;
typedef map<ll, ll> mllll;
typedef map<string, int> msi;
typedef map<char, int> mci;
typedef map<int, vi > mivi;
typedef map<string, vs > msvs;

vector<vi > board(9, vi(9,0));
mii subgrids;
map<int, pii> subgridStarts;

void printBoard() {
    int n = 9, x, y;
    range(0,n,1,x) {
        range(0,n,1,y)
            cout << ' ' << board[x][y] << ' ';
        cnl;
    };
};

bool valid(int loc, int number) {
    int x = loc / 9, y = loc % 9, u, v;
    pair<int, int> startLoc = subgridStarts[loc];

    range(0, 9, 1, u) if (board[u][y] == number) return false;
    range(0, 9, 1, v) if (board[x][v] == number) return false;
    range(startLoc.fi, startLoc.fi+3, 1, u)
        range(startLoc.se, startLoc.se+3, 1, v)
            if (board[u][v]==number) return false;

    return true;
};

void solve(int loc) {
    printBoard();
    if (loc == 81) {
        printBoard(); cnl;
        return;
    };

    int number; range(1, 10, 1, number) {
        if (valid(loc, number)) {
            int x = loc / 9, y = loc % 9;
            board[x][y] = number;
            solve(loc+1);
            board[x][y] = 0;
        };
    };
 
};

int main () {

    int z;

    // store subgrids based on location.
    range(0, 81, 1, z) {
        int x = z / 9, y = z % 9;
        if (x >= 0 && x < 3) {
            if (y >= 0 && y <= 3) subgrids[z] = 1;
            else if (y >= 3 && y < 6) subgrids[z] = 2;
            else subgrids[z] = 3;
        } else if (x >= 3 && x < 6) {
            if (y >= 0 && y <= 3) subgrids[z] = 4;
            else if (y >= 3 && y < 6) subgrids[z] = 5;
            else subgrids[z] = 6;
        } else {
            if (y >= 0 && y <= 3) subgrids[z] = 7;
            else if (y >= 3 && y < 6) subgrids[z] = 8;
            else subgrids[z] = 9;
        };
    };

    subgridStarts[1] = make_pair(0, 0);
    subgridStarts[2] = make_pair(0, 3);
    subgridStarts[3] = make_pair(0, 6);
    subgridStarts[4] = make_pair(3, 0);
    subgridStarts[5] = make_pair(3, 3);
    subgridStarts[6] = make_pair(3, 6);
    subgridStarts[7] = make_pair(6, 0);
    subgridStarts[8] = make_pair(6, 3);
    subgridStarts[9] = make_pair(6, 6);

    solve(0);

    return 0;
};