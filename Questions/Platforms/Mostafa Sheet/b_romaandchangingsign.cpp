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

class SegTree {
public:

    SegTree(vi &nums) {
        n = sz(nums);
        og = vi(n);
        int x; range(0, n,1, x)
            og[x] = nums[x];
        t = vi((n<<2)+1);
        mn = vpii((n<<2)+1, make_pair((int)1e8,(int)1e8));
        build(1, 0, n-1);
    };

    pii rangeMin(int v, int l, int r, int tl, int tr) {
        if (r < tl || tr < l) return make_pair((int)1e8,(int)1e8);
        else if (l >= tl && r <= tr) return mn[v];
        int m = (l+r)>>1, nv = v<<1;
        return minPair(rangeMin(nv, l, m, tl, tr), rangeMin(nv+1, m+1, r, tl, tr));
    };

    void pointUpdate(int v, int l, int r, int i, int x) {
        if (l == r) {
            t[v] = x;
            og[l] = x;
            mn[v].first = x;
            return;
        };

        int m = (l+r)>>1, nv = v<<1;
        if (i <= m) pointUpdate(nv, l, m, i, x);
        else pointUpdate(nv+1, m+1, r, i, x);
        t[v] += t[nv] + t[nv+1];
        mn[v] = minPair(mn[nv], mn[nv+1]);
    };

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

    void build(int v, int l, int r) {
        if (l == r) {
            t[v] = og[l];
            mn[v].first = og[l];
            mn[v].second = l;
            return;
        };

        int m = (l+r)>>1, nv = v<<1;
        build(nv, l, m); build(nv+1, m+1, r);
        t[v] += t[nv] + t[nv+1];
        mn[v] = minPair(mn[nv], mn[nv+1]);
    };

    pii minPair(pii a, pii b) {
        return a.first > b.first ? b : a;
    }

};

/*

https://codeforces.com/contest/262/problem/B

Time Complexity: O(N + KlogN)
Space Complexity: O(N)

*/

int main () {

    int n, k; cin >> n >> k;

    vi a(n);
    int x;
    range(0, n,1, x)
        cin >> a[x];
    
    SegTree st = SegTree(a);

    while (k--) {
        pii rmp = st.rangeMin(1, 0, sz(a)-1, 0, sz(a)-1);
        st.pointUpdate(1, 0, sz(a)-1, rmp.second, rmp.first*-1);
    };

    cout << st.sum() << "\n";

    return 0;
};