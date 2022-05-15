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

Time Complexity:
Space Complexity:

*/

bool comp(tuple<int,int,int,int> a, tuple<int,int,int,int> b) {
    int maxA = max(get<1>(a), get<3>(a)), maxB = max(get<1>(b), get<3>(b));
    return maxB > maxA;
}

int main () {

    int n, m; cin >> n >> m;
    
    int x, y;
    vpii pairs;
    map<int, int> freq;

    map<int, unordered_set<int>> graph;

    range(0, m, 1, x) {
        int u, v; cin >> u >> v;
        graph[u].ins(v), graph[v].ins(u);
        if (!freq.co(u)) freq[u]=1;
        else freq[u]++;

        if (!freq.co(v)) freq[v]=1;
        else freq[v]++;

        pairs.add(make_pair(u, v));
    };

    vector<tuple<int,int,int,int> > ordering;
    range(0, m, 1, x) {
        ordering.add(make_tuple(pairs[x].fi,freq[pairs[x].fi], pairs[x].se, freq[pairs[x].se]));
    }

    sorter(ordering, comp);

    int ans = 1;
    set<int> added;
    range(0, m, 1, x) {
        tuple<int,int,int,int> currPair = ordering[x];
        int u = get<0>(currPair), v = get<2>(currPair), ufreq = get<1>(currPair), vfreq = get<3>(currPair);
        
        if (ufreq > vfreq) {
            for (auto reactable: graph[u]) {
                if (added.co(reactable)) ans <<= 1;
                break;
            }

            added.ins(u);
            added.ins(v);

            for (auto reactable: graph[v]) {
                if (added.co(reactable)) ans <<= 1;
                break;
            }
        } else {
            for (auto reactable: graph[v]) {
                if (added.co(reactable)) ans <<= 1;
                break;
            }

            added.ins(u);
            added.ins(v);

            for (auto reactable: graph[u]) {
                if (added.co(reactable)) ans <<= 1;
                break;
            }
        }



    };

    cout << ans << "\n";


    return 0;
};