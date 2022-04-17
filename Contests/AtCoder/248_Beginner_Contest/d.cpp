#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;
 
 
class RangeCountSegTree {
 
public:
    RangeCountSegTree(vector<int> &elements) {
        og = vector<int>(elements.size());
        int x; range(0, elements.size(), 1, x)
            og[x] = elements[x];
        t = vector<unordered_map<int, int> >((elements.size()<<2)+1, unordered_map<int,int>());
 
        build(1, 0, elements.size()-1);
    };
 
 
    int countQuery(int v, int l, int r, int tl, int tr, int x) {
        if (r < tl || tr < l) return 0;
        else if (l >= tl && r <= tr) {
            if (!t[v].count(x)) return 0;
            return t[v][x];
        }
        int m = (l+r)>>1, nv = v<<1;
        return countQuery(nv, l, m, tl, tr, x) + countQuery(nv+1, m+1, r, tl, tr, x);
    };
 
 
 
private:
    vector<int> og;
    vector<unordered_map<int, int> > t;

    void build(int v, int l, int r) {
        if (l == r) {
            t[v][og[l]] = 1;
            return;
        };
 
        int x;
        int m = (l+r)>>1, nv = v<<1;
        build(nv, l, m); build(nv+1, m+1, r);
 
        unordered_map<int, int>::iterator itLeft = t[nv].begin(), itRight = t[nv+1].begin();
        while (itLeft != t[nv].end()) {
            int f = (*itLeft).first, s = (*itLeft).second;
            if (!t[v].count(f)) {
                t[v][f] = s;
            } else {
                t[v][f] += s;
            };
 
            itLeft++;
        };
 
        while (itRight != t[nv+1].end()) {
            int f = (*itRight).first, s = (*itRight).second;
            if (!t[v].count(f)) {
                t[v][f] = s;
            } else {
                t[v][f] += s;
            };
 
            itRight++;
        };
 
    }
 
 
};
 
 
int main () {
 
    int n; cin >> n;
    vector<int> elements(n);
    
    int x; range(0, elements.size(), 1, x) {
        cin >> elements[x];
    }
    
    int q; cin >> q;
    RangeCountSegTree st = RangeCountSegTree(elements);
    while (q--) {
        int l, r, x; cin >> l >> r >> x;
        cout << st.countQuery(1, 0, elements.size()-1, l-1, r-1, x) << "\n";
    }
 
    return 0;
}