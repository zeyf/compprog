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
typedef vector<char> vc;
typedef vector<vc > vvc;
typedef vector<vi > vvi;

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

Link: https://codeforces.com/contest/1676/problem/G

Topic: Graph Theory / Trees

Approach: Transpose the tree. Instead of child to parent directed edges, have parent to child directed edges.
This will make the recursive postorder solution trivial. DFS from one location, versus DFS from every leaf (and having to determine what is and is not a leaf via indegrees...)
However distinction of leaves is not relevant, they are a single node subtree, and they will always be out of balance.
Time Complexity: O(V)
Space Complexity: O(V)

*/

tuple<int, int, int> dfs(int u, mivi &graph, mii &colors) {

    // account for whether current node is white or black.
    int white = colors[u]==1, black = colors[u]==0, balanced = 0;

    // if not at leaf, meaning outdegree > 0
    if (graph.count(u)) {
        // iterate through edges.
        for (auto v: graph[u]) {
            // recurse and account for data of subtree.
            tuple<int, int, int> subResult = dfs(v, graph, colors);
            white += get<0>(subResult), black += get<1>(subResult), balanced += get<2>(subResult);
        };
    };

    // if the subtree of the current node is balanced, account for it and propagate data up tree.
    if (white == black) ++balanced;
    return make_tuple(white,black,balanced);
};

int main () {

    // tc test cases...
    int tc; cin >> tc;
    while (tc--) {

        // read in the data
        int n; cin >> n;
        mivi graph;
        mii colors;
        int x;
        range(1, n, 1, x) {
            // transpose the graph
            int xParent; cin >> xParent;
            graph[xParent].add(x+1);
        };

        // read in and assign the colors to the strings
        string s; cin >> s;
        range(0, s.size(), 1, x) {
            colors[x+1] = s[x] == 'W';
        };

        // dfs and print answer
        tuple<int, int, int> ans = dfs(1,graph,colors);
        cout << get<2>(ans) << "\n";

    }

    return 0;
};