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

Link: https://codeforces.com/contest/716/problem/B

Topic: Strings / Greedy / Two Pointers (1300)

Approach: Character Frequency Fenwick/Binary-Indexed Tree
Precalculated the number of characters for fast logN*26 range query look up.

Handled invalidation cases -- made a nice substring -- filled all other ? (if any) with random letter.


Time Complexity: N log(N)
Space Complexity: N*26


*/


int main () {

    // read in the string
    string s; cin >> s;
    int n = sz(s);

    // invalidation case
    if (n < 26) {
        cout << -1 nl;
        return 0;
    }

    // instantiate the frequency fenwick/binary-indexed tree to uppercase config!
    FREQBIT tree = FREQBIT(s, false);

    int x,y,z;

    bool found = false;
    range(0,n,1,x) {
        // if we can't have a substring of 26 characters after a certain index... break.
        if(x + 26 > n) break;

        // get the frequency of the current range (1 indexed)
        vector<int> freq = tree.rangeFrequency(x+1,x+26);
        
        // track if we have an invalid substring case...
        bool bad = false;

        // index 26 is for the ?'s, if we have none in the current substring...
        if (freq[26]==0) {
            // check for invalidation case of missing a letter or having more than 1 in the substring
            range(0,26,1,y) {
                if (freq[y] != 1) {
                    bad = true;
                    break;
                }
            }

            // if substring is invalidated, stop
            if (bad) {
                continue;
            }

            // iterate over the string, replace all ? to any value (I chose 'A')
            range(0,n,1,y) {
                if (s[y]=='?') s[y]='A';
            };

            // mark as answer found!
            found = true;

        } else {

            // track what letters are used (only one in the substring!)
            set<char> used;

            // check for invalidation case of missing a letter or having more than 1 in the substring
            // also account for the used 'good' letters...

            range(0,26,1,y) {
                if (freq[y] > 1) {
                    bad = true;
                    break;
                } else if (freq[y]==1) {
                    used.insert(y+'A');
                }
            };

            // if substring is invalidated, stop
            if (bad) continue;

            // iterate over all letters, store all characters that are not used to then place into substring ?'s.
            vector<char> options;
            range(0,26,1,y) {
                if (!used.count(y+'A')) options.add(y+'A');
            }

            // replace all ? in the substring with the letters we have not used in this valid case...
            range(x,x+26,1,y) {
                if (s[y]=='?') {
                    s[y] = options.back();
                    options.rem();
                }
            }

            // replace all other characters in the interval [min(x+26,n-1),n-1] with random letter (I chose 'A')
            range(0,n,1,y) {
                if (s[y]=='?') s[y]='A';
            }

            // mark as found
            found = true;
        };

        // break out
        if (found) break;

    };

    // if we have not found an answer, we cannot make a nice string
    if (!found) cout << -1 << "\n";

    // else print the answer
    else {
        cout << s << "\n";
    }

    return 0;
};