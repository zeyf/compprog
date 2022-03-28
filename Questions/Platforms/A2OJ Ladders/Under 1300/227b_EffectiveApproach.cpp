#include <bits/stdc++.h>
 
#define loop(s, e) for (int x = s; x < e; x++)
using namespace std;
 
int main () {
 
    int n, m;
    long long u = 0, v = 0;
    map<int, int> indexMap;
 
    cin >> n;
    loop(0,n) {
        int v; cin >> v; indexMap[v] = x;
    };
 
    cin >> m;
    loop(0, m) {
        int mq; cin >> mq;
        u += indexMap[mq]+1;
        v += n-indexMap[mq];
    };
 
    cout << u << " " << v << "\n";
 
    return 0;
}