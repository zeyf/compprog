#include <bits/stdc++.h>
 
#define loop(s, e) for (int x = s; x < e; x++)
using namespace std;
 
int main () {
 
    int n, k;
    cin >> n >> k;
    map<int, int> idx;
    deque<int> line;

    loop(0, n) {
        int v; cin >> v;
        idx[x+1] = v;
        line.push_back(x+1);
    };

    while (line.size() > 1) {
        int c = line.front();
        line.pop_front();
        if (idx[c]-k > 0) {
            idx[c] -= k;
            line.push_back(c);
        };
    };

    cout << line.back() << "\n";
 
    return 0;
}