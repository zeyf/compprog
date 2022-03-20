#include <iostream>
#include <vector>
using namespace std;

#define pb push_back
#define loop(startInc, endEx) for (int x = startInc; x < endEx; x++)
#define sz(x) (int)x.size()
#define pii pair<int, int>
#define f first
#define s second
#define mp(x,y) make_pair(x, y)

/*==================================================================*/
/*==================================================================*/
/*==================================================================*/

// Standard Segment Tree Implementation
class SegmentTree {
    public:
    SegmentTree(vector<int> &vals) {
        n = sz(vals);
        loop(0, n) og.pb(vals[x]);
        t = vector<int>((n<<1)+1, 0);
        build(1, 0, n-1);
    };

    long long rangeSum(int v, int l, int r, int tl, int tr) {
        if (r < tl || tr < l) return 0;
        else if (l >= tl && r <= tr) return t[v];

        int m = (l+r)>>1, nv = v<<1;
        return rangeSum(nv, l, m, tl, tr) + rangeSum(nv+1, m+1, r, tl, tr);
    };

    void pointUpdate(int v, int l, int r, int i, int x) {
        if (l == r) { t[v] = x; return; };

        int m = (l+r)>>1, nv = v<<1;
        if (i <= m) pointUpdate(nv, l, m, i, x);
        else pointUpdate(nv+1, m+1, r, i, x);
        t[v] = t[nv] + t[nv+1];
    };

    private:
    int n;
    vector<int> t, og;

    void build(int v, int l, int r) {
        if (l==r) { t[v] = og[l]; return; };

        int m = (l+r)>>1, nv = v<<1;
        build(nv, l, m);
        build(nv+1, m+1, r);
        t[v] = t[nv] + t[nv+1];
    };

};

/*==================================================================*/
/*==================================================================*/
/*==================================================================*/

// Min Max Non Indexed Segment Tree Implementation
class NonIndexedMinMaxSegmentTree {
    public:
    NonIndexedMinMaxSegmentTree(vector<int> &vals) {
        n = sz(vals);
        loop(0, n) og.pb(vals[x]);
        t = vector<int>((n<<1)+1, 0);
        mn = vector<int>((n<<1)+1, 0);
        mx = vector<int>((n<<1)+1, 0);
        build(1, 0, n-1);
    };

    long long rangeSum(int v, int l, int r, int tl, int tr) {
        if (r < tl || tr < l) return 0;
        else if (l >= tl && r <= tr) return t[v];
        
        int m = (l+r)>>1, nv = v<<1;
        return rangeSum(nv, l, m, tl, tr) + rangeSum(nv+1, m+1, r, tl, tr);
    };

    int rangeMin(int v, int l, int r, int tl, int tr) {
        if (r < tl || tr < l) return 1e8;
        else if (l >= tl && r <= tr) return mn[v];

        int m = (l+r)>>1, nv = v<<1;
        return min(rangeMin(nv, l, m, tl, tr), rangeMin(nv+1, m+1, r, tl, tr));
    };

    int rangeMax(int v, int l, int r, int tl, int tr) {
        if (r < tl || tr < l) return -1e8;
        else if (l >= tl && r <= tr) return mx[v];

        int m = (l+r)>>1, nv = v<<1;
        return max(rangeMax(nv, l, m, tl, tr), rangeMax(nv+1, m+1, r, tl, tr));
    };

    void pointUpdate(int v, int l, int r, int i, int x) {
        if (l == r) { t[v] = mn[v] = mx[v] = x; return; };

        int m = (l+r)>>1, nv = v<<1;
        if (i <= m) pointUpdate(nv, l, m, i, x);
        else pointUpdate(nv+1, m+1, r, i, x);
        t[v] = t[nv] + t[nv+1];
        mn[v] = min(mn[nv], mn[nv+1]);
        mx[v] = max(mx[nv], mx[nv+1]);
    };

    private:
    int n;
    vector<int> t, og, mn, mx;

    void build(int v, int l, int r) {
        if (l==r) { t[v] = mn[v] = mx[v] = og[l]; return; };

        int m = (l+r)>>1, nv = v<<1;
        build(nv, l, m);
        build(nv+1, m+1, r);
        t[v] = t[nv] + t[nv+1];
        mn[v] = min(mn[nv], mn[nv+1]);
        mx[v] = max(mx[nv], mx[nv+1]);
    };

};

/*==================================================================*/
/*==================================================================*/
/*==================================================================*/

// Min Max Indexed Segment Tree Implementation
class IndexedMinMaxSegmentTree {
    public:
    IndexedMinMaxSegmentTree(vector<int> &vals) {
        n = sz(vals);
        loop(0, n) og.pb(vals[x]);
        t = vector<int>((n<<1)+1, 0);
        mn = vector<pii>((n<<1)+1, mp(0,0));
        mx = vector<pii>((n<<1)+1, mp(0,0));
        build(1, 0, n-1);
    };

    long long rangeSum(int v, int l, int r, int tl, int tr) {
        if (r < tl || tr < l) return 0;
        else if (l >= tl && r <= tr) return t[v];
        
        int m = (l+r)>>1, nv = v<<1;
        return rangeSum(nv, l, m, tl, tr) + rangeSum(nv+1, m+1, r, tl, tr);
    };

    pii rangeMin(int v, int l, int r, int tl, int tr) {
        if (r < tl || tr < l) return mp(1e8,1e8);
        else if (l >= tl && r <= tr) return mn[v];

        int m = (l+r)>>1, nv = v<<1;
        return minPair(rangeMin(nv, l, m, tl, tr), rangeMin(nv+1, m+1, r, tl, tr));
    };

    pii rangeMax(int v, int l, int r, int tl, int tr) {
        if (r < tl || tr < l) return mp(-1e8,-1e8);
        else if (l >= tl && r <= tr) return mx[v];

        int m = (l+r)>>1, nv = v<<1;
        return maxPair(rangeMax(nv, l, m, tl, tr), rangeMax(nv+1, m+1, r, tl, tr));
    };

    void pointUpdate(int v, int l, int r, int i, int x) {
        if (l == r) {
            t[v] = mn[v].f = mx[v].f = x;
            return;
        };

        int m = (l+r)>>1, nv = v<<1;
        if (i <= m) pointUpdate(nv, l, m, i, x);
        else pointUpdate(nv+1, m+1, r, i, x);
        t[v] = t[nv] + t[nv+1];
        mn[v] = minPair(mn[nv], mn[nv+1]);
        mx[v] = maxPair(mx[nv], mx[nv+1]);
    };

    private:
    int n;
    vector<int> t, og;
    vector<pii> mn, mx;

    void build(int v, int l, int r) {
        if (l==r) {
            t[v] = mn[v].f = mx[v].f = og[l];
            mn[v].s = mx[v].s = l;
            return;
        };

        int m = (l+r)>>1, nv = v<<1;
        build(nv, l, m);
        build(nv+1, m+1, r);
        t[v] = t[nv] + t[nv+1];
        mn[v] = min(mn[nv], mn[nv+1]);
        mx[v] = max(mx[nv], mx[nv+1]);
    };

    pii minPair(pii u, pii v) { return u.f > v.f ? v : u; };
    pii maxPair(pii u, pii v) { return u.f > v.f ? u : v; };

};