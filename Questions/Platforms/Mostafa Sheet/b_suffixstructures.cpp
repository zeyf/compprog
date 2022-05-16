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

Link: https://codeforces.com/contest/448/problem/B

Topic: Strings / Subsequences (Implementation - 1400)

Approach:

Disqualify simple case -- more letters in t than s, need tree.
If t is a subsequence of s, then we can have done so with just an automaton. Sure, array could have been used but not changed subsequence qualification.
If frequencies of a letter in t exceed those of s, need tree.

If the s and t length are same and not subsequence -- array case
If t length is < s length and non subsequence -- both case

Time Complexity: O(S+T)
Space Complexity: O(1)

*/


int main () {

    string s, t; cin >> s >> t;

    // simple invalidation check.
    if (sz(t) > sz(s)) {
        cout << "need tree\n";
        return 0;
    };

    vector<int> freqS(26,0), freqT(26,0);
    int x = 0, y = 0;

    // check if t is a subsequence of s, and frequency count s
    for (auto c: s) {
        freqS[c-'a']++;
        if (t[x]==c) x++;
    };

    // frequency count t
    for (auto c: t) {
        freqT[c-'a']++;
    }

    // t is subsequence of s, we only removed letters, or swaps didn't change subsequence capability, only automaton.
    if (x == sz(t)) {
        cout << "automaton\n";
    } else {

        // since automaton only removes, and array only swaps, if we have additional characters in t not in s, need tree
        for (auto c: t) {
            if (freqT[c-'a'] > freqS[c-'a']) {
                cout << "need tree\n";
                return 0;
            };
        };

        // if we have the same length, we did not remove characters
        if (sz(t)==sz(s)) {
            cout << "array\n";

        // we can only be lesser than, so since not subsequence and not >=, must be non subsequence and <. therfore, both.
        } else {
            cout << "both\n";
        }

    };

    return 0;
};