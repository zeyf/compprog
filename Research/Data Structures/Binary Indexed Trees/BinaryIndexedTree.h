#include <bits/stdc++.h>
using namespace std;

/*

=============================
Binary Indexed / Fenwick Tree
=============================

- Prefix Sum
- Range Sum
- Point Update

*/

typedef long long ll;

class BinaryIndexedTree {
public:
    BinaryIndexedTree(vector<ll> &a) {
        // create the array for the tree. must be 1 indexed
        pfs = vector<ll>(a.size()+1, 0);
 
        // build the tree, iterate through the tree and seed with values from original array.
        // propagate values forwards to children if in bounds.
        for (int x = 1; x < pfs.size(); x++) {
            pfs[x] += a[x-1];
            if (x+lob(x) < pfs.size()) pfs[x+lob(x)] += pfs[x];
        }
    }
 
    // performs a prefix sum. propagate downwards from child to parents with binary lifting
    ll prefixSum(int x) {
        ll sum = 0;
        while (x > 0) {
            sum += pfs[x];
            x -= lob(x);
        };
        return sum;
    }
 
    // performs a rangeSum by inclusion exclusion principle on prefixSum range.
    // sum out undesired subset sum
    ll rangeSum(int x, int y) {
        return prefixSum(y)-prefixSum(x-1);
    }
 
    // performs an update at a given index.    
    void pointUpdate(int index, ll to) {
        // finds the value of the single index.
        int previousValue = rangeSum(index, index);
 
        // makes sure all propagated sums that are dependent on node at index are updated
        // remove the previous value from the children, starting at index, and add the new value.
        while (index < pfs.size()) {
            pfs[index] = pfs[index] - previousValue + to;
            index += lob(index);
        };
    };
 
private:
    vector<ll> pfs;
    int lob(int index) {return index & -index;}
};