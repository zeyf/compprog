#include <bits/stdc++.h>
using namespace std;

#define UNVISITED (int)1e9
typedef map<int, vector<int> > mpivi;
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)

map<int, vector<int> >  graph;
vector<int> in(100001), lowLink(100001);
set<pair<int, int> > roads;
set<int> visited;

bool findBridges(int u, int parent, int &time) {
    in[u] = lowLink[u] = time++;
    visited.insert(u);

    int x;
    range(0, graph[u].size(), 1, x) {
        int nbr = graph[u][x];
        if (nbr == parent) continue;
        
        if (!visited.count(nbr)) {
            if (findBridges(nbr, u, time))
                return true;
            
            if (lowLink[nbr] > lowLink[u])
                return true;
            lowLink[u] = min(lowLink[u], lowLink[nbr]);
            
            if (!roads.count(make_pair(u, nbr)) && !roads.count(make_pair(nbr, u)))
                roads.insert(make_pair(u, nbr));
        } else {
            lowLink[u] = min(lowLink[u], in[nbr]);
            if (!roads.count(make_pair(u, nbr)) && !roads.count(make_pair(nbr, u)))
                roads.insert(make_pair(u, nbr));
        };

    };

    return false;
};

int main () {
    int n, m; cin >> n >> m;
    int root = UNVISITED;

    while (m--) {
        int u, v; cin >> u >> v;
        if (!graph.count(u))
            graph[u] = vector<int>();
        if (!graph.count(v))
            graph[v] = vector<int>();
        graph[u].push_back(v);
        graph[v].push_back(u);
        root = u;
    };

    int time = 0;
    if (findBridges(root, root, time))
        cout << 0 << "\n";
    else {
        set<pair<int, int> >::iterator it = roads.begin();
        while (it != roads.end()) {
            cout << (*it).first << " " << (*it).second << "\n";
            it++;
        };
    };

    return 0;
};