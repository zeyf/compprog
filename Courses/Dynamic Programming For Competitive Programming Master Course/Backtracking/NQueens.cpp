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


#define QUEEN '$'

/*

valid placement:
    Considering placement will be done left to right, from the top (bottom) row to the bottom (top) row,
    we DO NOT need to check to our:
        - Straight right
        - Straight down
        - Diagonally down left
        - Diagonally down right
    however we must check:
        - Straight left
        - Straight up
        - Diagonally up left
        - Diagonally up right
        - if a queen is placed at any of these locations, cannot be placed.


If location is valid to place, place and do not place to find all valid subsets.

Primary base case:
- n*n has been reached
    - n queens have been placed (0 left)
        - print the board
        - return
    - less than n queens have been placed
        - return
- n*n has not been reached
    - n queens have been placed (0 left)
        - print the board
        - return

*/

// prints the board
void printBoard(vector<vector<char> > &board) {
    int n = sz(board), x, y;
    range(0,n,1,x) {
        range(0,n,1,y)
            cout << ' ' << board[x][y] << ' ';
        cnl;
    };
};

// Note: before this function is called, the queen is NOT placed, NOR IS IT PLACED in this function.
// verify the position from a previously placed Queen's possibility of attack
bool valid(vector<vector<char> > &board, int x, int y) {
    int a = x, b = y, n = sz(board);

    // check above
    a--;
    while (a >= 0) 
        if (board[a--][y] == QUEEN) return false;

    // check to the left
    b--;
    while (b >= 0)
        if (board[x][b--] == QUEEN) return false;
    
    a = x-1; b = y-1;
    // check the up-left diagonal
    while (a >= 0 && b >= 0)
        if (board[a--][b--] == QUEEN) return false;
    
    a = x-1; b = y+1;

    // check the up right diagonal
    while (a >= 0 && b < n)
        if (board[a--][b++] == QUEEN) return false;

    // good to place.
    return true;
};

int NQueens(vector<vector<char> > &board, int loc, int left) {
    int n = sz(board);
    // if we have nowhere else to place...
    if (loc == n*n) {
        // if we have no more queens to place...
        if (left == 0) {
            printBoard(board);
            cnl;
            return 1;
        };
        return 0;
    
    // if we have places we can place a queen, but we have no more queens...
    } else if (left == 0) {
        printBoard(board);
        cnl;
        return 1;
    };

    // decode the position.
    int ans = 0, x = loc / n, y = loc % n;

    // if we can place a queen here...
    if (valid(board, x, y)) {
        // store the previous to backtrack!
        char prev = board[x][y];
        // place the queen!
        board[x][y] = QUEEN;
        // recurse! account for the placed queen at 1...
        ans += NQueens(board, loc+1, left-1);

        // backtrack!
        board[x][y] = prev;
    };
    
    // handles where there may have been a valid place, but did not place.
    // If not a valid position, wouldn't place anyways.
    ans += NQueens(board, loc+1, left);

    return ans;
};

// makes the pretty chessboard pattern.
void makeChessBoard(vector<vector<char> > &board) {
    int n = sz(board), x, y, a, b;

    // given the board is predefaulted to black, '#', skip a row between diagonal iterations of white, '_'
    range(0,n,2,x) {
        range(0,n,2,y) {
            // this diagonal is already colored!
            if (board[x][y] == '_') continue;

            a = x; b = y;
            while (a < n && b < n) {
                board[a][b] = '_';
                a++; b++;
            };
        };
    };
};

int main () {

    // read in n, make the board and default to black, '#'
    int n; cin >> n;
    vector<vector<char> > board(n, vector<char>(n, '#'));

    // "make" the chessboard -- give it it's pattern...
    makeChessBoard(board);

    // solve the NQueens problem!
    NQueens(board, 0, n);

    return 0;
};