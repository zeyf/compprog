#include <iostream>
#include <vector>
#include <queue>

#define loop(s, e) for (int x = s; x < e; x++)
#define uloop2(s, e) for (int y = s; y < e; y++)
#define dloop1(s, e) for (int x = s; x > e; x--)
#define dloop2(s, e) for (int y = s; y > e; y--)

/*

Idea:

Simple BFS.

*/

using namespace std;

int main () {

    int n; cin >> n;
    int dim = (n<<1)+1;
    int dr[] = { -1, 0, 0, 1 }, dc[] = { 0, -1, 1, 0 };
    vector<vector<char> > board(dim, vector<char>(dim, ' '));
    queue<pair<int,int> > q;

    q.push(make_pair(dim>>1, dim>>1));
    board[dim>>1][dim>>1] = 48+n;
    n--;

    while (q.size() > 0 && n >= 0) {
        int size = q.size();
        while (size--) {
            pair<int, int> currLoc = q.front();
            q.pop();

            loop(0, 4) {
                pair<int, int> nextLoc = make_pair(currLoc.first+dr[x], currLoc.second+dc[x]);
                if (nextLoc.first >= 0 && nextLoc.second >= 0 && nextLoc.first < dim && nextLoc.second < dim && board[nextLoc.first][nextLoc.second] == ' ') {
                    board[nextLoc.first][nextLoc.second] = 48+n;
                    q.push(nextLoc);
                };
            };
        };

        n--;
    };

    loop(0, dim) {
        uloop2(0, dim)
            cout << board[x][y] << " ";
        cout << "\n";
    };

    return 0;
}