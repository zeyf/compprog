#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
 
using namespace std;

/*DEFINES*/
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
#define sorter(a, comp) sort(a.begin(), a.end(), comp)
#define sz(a) a.size()
#define add push_back
#define rem pop_back
#define ins insert
#define co count
#define fi first
#define se second
#define nl << "\n"
#define cnl cout << "\n"

/*TYPEDEFS*/
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pllll;
typedef set<int> si; typedef set<ll> sll; typedef set<string> ss; typedef set<pii > spii; typedef set<pllll > spllll;
typedef vector<int> vi; typedef vector<ll> vll; typedef vector<string> vs; typedef vector<pii > vpii; typedef vector<char> vc; typedef vector<vc > vvc; typedef vector<vi > vvi;
typedef map<int, int> mii; typedef map<ll, ll> mllll; typedef map<string, int> msi; typedef map<char, int> mci; typedef map<int, vi > mivi; typedef map<string, vs > msvs;

/*CLASSES*/
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

mii locations;
void swap(int x, int y) {
	int temp = locations[x];
	locations[x] = locations[y];
	locations[y] = temp;
}

bool comp(pii a, pii b) {
	return b.first > a.first;
}

int main () {

	int n, q; cin >> n >> q;

	int x; range(0, n, 1, x)
		locations[x+1]=x+1;
	
	int ogRightMost = n;
	bool movedRightMost = false;

	while (q--) {
		int query; cin >> query; query--;
		if (query == n-1) {
			if (!movedRightMost) {
				movedRightMost = true;
				swap(query,query-1);
			}
		} else {
			if (query==ogRightMost && movedRightMost) {
				if (query>0) swap(query, query-1);
			} else {
				swap(query,query+1); 
			};
		}
	}

	auto it = locations.begin();
	vector<pii > pairs;
	while (it != locations.end()) {
		pairs.push_back(make_pair(it->second, it->first));
		it++;
	}

	sorter(pairs, comp);

	range(0, n, 1, x)
		cout << pairs[x].second << " ";
	cnl;
	

    return 0;
};