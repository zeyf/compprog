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
CLASSES
*/

class UnionFind {
	public:
		UnionFind(unsigned int size) {
			n = numComponents = size;
			sets = vector<int>(size);
			cards = vector<int>(size);
			for (int x = 0; x < n; x++) {
				sets[x] = x;
				cards[x] = 1;
			};
		};

		int find(int u) {
			if (u == sets[u]) return u;
			return (sets[u] = find(sets[u]));
		};

		bool uni(int u, int v) {
			int uSet = find(u), vSet = find(v);
			if (uSet == vSet) return false;

			if (cards[uSet] > cards[vSet]) {
				cards[uSet] += cards[vSet];
				cards[vSet] = 0;
				sets[vSet] = uSet;
			} else {
				cards[vSet] += cards[uSet];
				cards[uSet] = 0;
				sets[uSet] = vSet;
			};

			numComponents--;
			return true;
		};
		
		bool sameSet(int u, int v) { return find(u) == find(v); };

		unsigned int getSetsCount() { return numComponents; };

		int getSetSize(int u) { return cards[find(u)]; };

	private:
		unsigned int n, numComponents;
		vector<int> sets, cards;
};

class FREQBIT {
public:
    FREQBIT(string s, bool lowercase) {
        pfs = vector<vector<int>>(s.size()+1, vector<int>(27,0));
 
        for (int x = 1; x < pfs.size(); x++) {
            if (s[x-1]!='?')
                pfs[x][s[x-1]-(lowercase ? 'a' : 'A')]++;
            else
                pfs[x][26]++;

            if (x+lob(x) < pfs.size()) {
                for (int y = 0; y < 27; ++y) {
                    pfs[x+lob(x)][y] += pfs[x][y];
                }
            }

        }
    }
 
    vector<int> prefixFrequency(int x) {
        vector<int> frequencies(27,0);

        while (x > 0) {
            for (int y = 0; y < 27; ++y) {
                frequencies[y] += pfs[x][y];
            }

            x -= lob(x);
        };
        return frequencies;
    }
 
    vector<int> rangeFrequency(int x, int y) {
        vector<int> upper = prefixFrequency(y), lower = prefixFrequency(x-1);
        for (int z = 0; z < 27; ++z)
            upper[z] -= lower[z];
        return upper;
    }
 
private:
    vector<vector<int>> pfs;
    int lob(int index) {return index & -index;}
};

/*

Link: https://codeforces.com/contest/791/problem/B

Topics: Graph Theory -- Cliques

Did not know the technique nor the numerical definitions and constraints behind cliques.

Time Complexity: O(V+E)
Space Complexity: O(V+E)


*/


set<int> visited;
mivi graph;

void dfs(int u, ll &ccE, ll &ccV) {
    ccV++;
    ccE += sz(graph[u]);
    visited.insert(u);
    
    for (auto v: graph[u]) {
        if (!visited.count(v)) dfs(v,ccE,ccV);
    };
}

int main () {

    int n, e; cin >> n >> e;

    while (e--) {
        int u, v; cin >> u >> v;
        graph[u].add(v),graph[v].add(u);
    };

    int u;
    range(1,n+1,1,u) {
        if (!visited.count(u)) {
            ll ccEdges = 0, ccVertices = 0;
            dfs(u,ccEdges,ccVertices);
            if (ccEdges != ccVertices*(ccVertices-1)) {
                cout << "NO\n";
                return 0;
            }
        }
    } 

    cout << "YES\n";

    return 0;
};