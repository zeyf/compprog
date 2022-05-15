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

class BIT {
public:
    BIT(vector<ll> &a) {
        pfs = vector<ll>(a.size()+1, 0);
 
        for (int x = 1; x < pfs.size(); x++) {
            pfs[x] += a[x-1];
            if (x+lob(x) < pfs.size()) pfs[x+lob(x)] += pfs[x];
        }
    }
 
    ll prefixSum(int x) {
        ll sum = 0;
        while (x > 0) {
            sum += pfs[x];
            x -= lob(x);
        };
        return sum;
    }
 
    ll rangeSum(int x, int y) {
        return prefixSum(y)-prefixSum(x-1);
    }
   
    void pointUpdate(int index, ll to) {
        int previousValue = rangeSum(index, index);
        while (index < pfs.size()) {
            pfs[index] = pfs[index] - previousValue + to;
            index += lob(index);
        };
    };
 
private:
    vector<ll> pfs;
    int lob(int index) {return index & -index;}
};

/*

Link:

Topic:

Approach:

Time Complexity: O(N*M + S*L*(N*M - L))

Explanation:

We have to read in the board, so that is N*M.

L is the number of shift keys in the board
S is the length of the string

For every key in the string, we have to iterate up to L characters, and at worst,
can't make any of the letters, we have all uppercase letters (all in alphabet)

And in the board, there are at most N*M - L lowercase letters in the board (exclude the shift keys)

Space Complexity: idk

*/

vector<pii> shifts;

int main () {

    int n, m, k; cin >> n >> m >> k;
    vector<pii> keys[26];


    // read in the board
    int x, y;
    range(0,n,1,x) {
        range(0,m,1,y) {
            char c; cin >> c;
            // if we read in a shift key, add to shifts key locations vector
            if (c=='S') {
                shifts.add(make_pair(x,y));
            
            // if we read in a non shift key, it is lowercase, add it to the keys respective location
            } else {
                keys[c-'a'].add(make_pair(x,y));
            };
        }
    }


    // read in the string and its length
    int len;
    string s;
    cin >> len >> s;

    // instantiate the map to see if uppercase letters are able to be placed with 1 hand.
    map<char, bool> upperGood;

    // check for invalidation of the string
    for (char c: s) {
        // if we have an uppercase letter in the string
        if (c >= 'A' && c <= 'Z') {
            // if we do not have any shift keys or that lowercase letter is not on the board, -1. we can't make word
            if (sz(shifts)==0 || sz(keys[c+32-'a']) == 0) {
                cout << -1 nl;
                return 0;
            }

            // else assume we can do it!
            upperGood[c]=true;
        
        // if we have a lowercase letter in the string
        } else {
            // if we do not have this letter on the keyboard
            if (sz(keys[c-'a']) == 0) {
                cout << -1 nl;
                return 0;
            };
        };
    }

    int ans = 0;

    // iterate over the string
    for (char c: s) {

        // if uppercase...
        if (c >= 'A' && c <= 'Z') {
            // if we have previously processed this letter and know it needs 2 hands, account for it, continue
            if (!upperGood[c]) {
                ans++;
                continue;
            };

            bool good = false;

            // iterate over all combinations of shift keys and locations of a letter, see if we can type without 2 hands
            range(0,sz(shifts),1,x) {
                range(0,sz(keys[c+32-'a']),1,y) {
                    // get the locations of shift and the letter
                    int x1 = shifts[x].fi, x2 = keys[c+32-'a'][y].fi,
                        y1 = shifts[x].se, y2 = keys[c+32-'a'][y].se;
                    
                    // check if we can type without two hands at given combination
                    good = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) <= k*k;

                    if (good) break;

                };

                if (good) break;
            }

            // if we can't type at distance less than k, account for current letter and mark as no.
            // hash the answers for same character to save computation.
            if (!good) {
                ans++;
                upperGood[c]=false;
            };

        };
    };

    // print the answer
    cout << ans nl;


    return 0;
};