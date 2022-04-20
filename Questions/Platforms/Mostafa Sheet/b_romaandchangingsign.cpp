#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*DEFINES*/

#define pushb push_back
#define popb pop_back
#define ins insert
#define co count
#define sorter(a, comp) sort(a.begin(), a.end(), comp)
#define sz(a) sz.size()


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
typedef set<char> sc;

/*
VECTOR TYPEDEFS
*/

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pii > vpii;
typedef vector<char > vc;
typedef vector<pllll > vpllll;

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

Link: https://codeforces.com/contest/262/problem/B

Topic: Range Query / Point Updates / Segment Tree

Solution: Slapped a Seg Tree on it for indexable range minimum queries for/with pointUpdate.

Time Complexity: O(N + KlogN)
Space Complexity: O(N)

*/

class SegTree {
public:

    SegTree(vi &nums) {
        n = sz(nums);
        og = vi(n);

        // copy values.
        int x; range(0, n,1, x)
            og[x] = nums[x];
        
        // initialize the vectors.
        t = vi((n<<2)+1);
        mn = vpii((n<<2)+1, make_pair((int)1e8,(int)1e8));

        // build the seg tree...
        build(1, 0, n-1);
    };

    // perform an indexed minimum range query...
    pii rangeMin(int v, int l, int r, int tl, int tr) {
        // if disjoint... base case.
        if (r < tl || tr < l) return make_pair((int)1e8,(int)1e8);
        // if subset...
        else if (l >= tl && r <= tr) return mn[v];

        // traverse and return the min pair...
        int m = (l+r)>>1, nv = v<<1;
        return minPair(rangeMin(nv, l, m, tl, tr), rangeMin(nv+1, m+1, r, tl, tr));
    };

    // updates a value at a given index...
    void pointUpdate(int v, int l, int r, int i, int x) {
        // if at leaf node... update.
        if (l == r) {
            t[v] = x;
            og[l] = x;
            mn[v].first = x;
            return;
        };

        // traverse...
        int m = (l+r)>>1, nv = v<<1;
        if (i <= m) pointUpdate(nv, l, m, i, x);
        else pointUpdate(nv+1, m+1, r, i, x);

        // update sum and minimum.
        t[v] += t[nv] + t[nv+1];
        mn[v] = minPair(mn[nv], mn[nv+1]);
    };

    // sums the current state of the seg tree!
    int sum() {
        int s = 0;
        for (auto val: og)
            s+= val;
        return s;
    }

private:

int n;
vi t, og;
vpii mn;

    // builds the seg tree
    void build(int v, int l, int r) {
        // if at a leaf node of interval... place value, set minimum data.
        if (l == r) {
            t[v] = og[l];
            mn[v].first = og[l];
            mn[v].second = l;
            return;
        };

        // traverse to the left and right...
        int m = (l+r)>>1, nv = v<<1;
        build(nv, l, m); build(nv+1, m+1, r);

        // update current sum, bring up the min pair...
        // as i annotate this, i realize i didnt need sum... did it subconciously, most seg tree need this. this wasnt the case here.
        t[v] += t[nv] + t[nv+1];
        mn[v] = minPair(mn[nv], mn[nv+1]);
    };

    // returns the minimum value pair of the two...
    pii minPair(pii a, pii b) {
        return a.first > b.first ? b : a;
    }

};

int main () {

    // Read in numbers
    int n, k; cin >> n >> k;

    // Read in data
    vi a(n);
    int x;
    range(0, n,1, x)
        cin >> a[x];
    
    // initialize the segment tree of the sequence.
    SegTree st = SegTree(a);

    // perform k operations...
    while (k--) {
        // perform a range minimum query (indexed).
        // This will return the smallest value and index in the data set, really in O(1) as it checks the whole range.
        pii rmp = st.rangeMin(1, 0, sz(a)-1, 0, sz(a)-1);

        // performs a point update, which is log(n). Flips this value to positive.
        st.pointUpdate(1, 0, sz(a)-1, rmp.second, rmp.first*-1);
    };

    // return the sum of the current state of the segment tree after k operations...
    cout << st.sum() << "\n";

    return 0;
};