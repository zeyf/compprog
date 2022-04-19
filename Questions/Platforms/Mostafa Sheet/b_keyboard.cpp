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



int main () {

    // Read in 
    int n, m, k; cin >> n >> m >> k;

    // initialize everything
    vector<vector<char> > board(n, vector<char>(m, '_'));
    unordered_set<char> letters;
    queue<pair<pii, pii> > q;
    set<pii > visited;
    map<char, double> distances;

    // read in the board
    int x, y;
    range(0, sz(board), 1, x) {
        range(0, sz(board[x]), 1, y) {
            cin >> board[x][y];
            
            // if a shift key
            if (board[x][y] == 'S') {
                // add to queue, mark in distances, change letter, mark visited
                q.push(make_pair(make_pair(x,y), make_pair(x,y)));
                distances['_'] = 0;
                board[x][y] = '_';
                visited.insert(make_pair(x, y));
            } else {
                // add possible letters in
                letters.ins(board[x][y]);
                letters.ins(board[x][y]-32);
            }
        };
    };

    int len; string s; cin >> len >> s;

    // invalidate cases
    for (char c: s) {
        // if letter not found or uppercase and no shift key
        if (!letters.co(c) || (c >= 65 && c<=90 && visited.size()==0)) {
            cout << "-1\n";
            return 0;
        };
    };


    int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 };

    // multisource bfs
    while (q.size() > 0) {
        pair<pii, pii > c = q.front();
        //cout << "(" << c.first << "," << c.second << ")" << "\t" << board[c.first][c.second] << "\t" <<  distances[board[c.first][c.second]] << "\n";
        q.pop();

        // iterate through all adjacent directions
        int x; range(0, 4, 1, x) {
            int nr = c.first.first+dx[x], nc = c.first.second+dy[x];
            // if inbounds and not visited
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited.count(make_pair(nr,nc))) {
                // calculate euclidean distance
                visited.insert(make_pair(nr, nc));
                q.push(make_pair(make_pair(nr,nc),make_pair(c.second.first,c.second.second)));
                distances[board[nr][nc]] = sqrt( (nr-c.second.first)*(nr-c.second.first) + (nc-c.second.second)*(nc-c.second.second) );
            }
        }

    };

    int ans = 0;
    for (char c: s) {
        if (c >= 65 && c <= 90) {
            if (distances[c+32] > k) {
                //cout << "TWO HAND!\t" << string(1,c+32);
                ans++;
            };
        }
    }

    cout << ans << "\n";

    return 0;
};