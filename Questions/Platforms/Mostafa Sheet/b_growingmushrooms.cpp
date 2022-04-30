#include <bits/stdc++.h>
#include <stdio.h>
 
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

Link: https://codeforces.com/contest/186/problem/B

Topic: Greedy / Sorting

Solution: Store pairs of index (time in) and the maximal mushroom height based on
two equations of different speed usages before and after the k percent reduction.

Then, sort the array based on multiple metrics:
If they have the same maximal height, sort ascending by the index, else descending by height.

*/

bool comp(pair<double, int> a, pair<double, int> b) {
    return b.first == a.first ? (a.second > b.second) : (b.first > a.first);
}

int main () {

    int n, t1, t2, k; cin >> n >> t1 >> t2 >> k;

    vector<pair<double, int> > f1(n, make_pair(0,0));
    int x;

    range(0,n,1,x) {
        int s1, s2; cin >> s1 >> s2;
        f1[x].second = x+1;
        f1[x].first = max((double)t1*s1*(1-k/100.0)+t2*s2, (double)t1*s2*(1-k/100.0)+t2*s1);
    };

    sorter(f1, comp);

    while (sz(f1)) {
        printf("%d %.2lf\n", f1.back().second, f1.back().first);
        f1.rem();
    };

    return 0;
};