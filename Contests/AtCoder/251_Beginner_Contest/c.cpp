#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
 
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

Time Complexity:
Space Complexity:

*/

// original sumission: stirng never been inserted before
// best submission if it is original and it has the highest score
// idea map

int main () {

	map<string, pllll > scores;
	int n; cin >> n;
	int x;

	range(0,n,1,x) {
		string s;
		ll t; cin >> s >> t;
		if (!scores.co(s)) {
			scores[s] = make_pair(t,x+1);
		};
	};

	ll bestscore = -1, bestindex = -1;

	auto it = scores.begin();
	while (it != scores.end()) {
		string word = it->first;
		pllll data = it->second;
		if (data.first > bestscore) {
			bestscore = data.first;
			bestindex = data.second;
		} else if (data.first == bestscore) {
			if (data.second <= bestindex) {
				bestindex = data.second;	
			};
		};
		it++;
	}

	cout << bestindex nl;


    return 0;
};