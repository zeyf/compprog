#include <bits/stdc++.h>
using namespace std;

#define UNVISITED (int)1e8

template<typename T>
class SimpleGraph {

public:
    SimpleGraph(bool undir);

    void addEdge(T u, T v) {

        if (!adjlist.count(u))
            adjlist[u] = vector<T>();
        if (!adjlist.count(v))
            adjlist[v] = vector<T>();

        adjlist[u].push_back(v);
        if (undirected) adjlist[v].push_back(u);
        
        vertices.insert(u);
        vertices.insert(v);
    };

    set<T> getVertices() {
        return vertices;
    };

    vector<T> getVertexEdges(T u) {
        return adjlist[u];
    }

private:
    map<T, vector<T> > adjlist;
    set<T> vertices;
    bool undirected;

};

template <typename T>
SimpleGraph<T>::SimpleGraph(bool undir) {
    undirected = undir;
    vertices = set<T>();
};

void findBridges(int u, SimpleGraph<int> &graph, vector<int> &in, vector<int> &lowLink, set<int> &visited, int &time, int parent) {

    in[u] = lowLink[u] = time++;
    visited.insert(u);

    for (int x = 0; x < graph.getVertexEdges(u).size(); x++) {
        int nbr = graph.getVertexEdges(u)[x];
        if (nbr == parent) continue;

        if (!visited.count(nbr)) {
            findBridges(nbr, graph, in, lowLink, visited, time, u);
            lowLink[u] = min(lowLink[u], lowLink[nbr]);
            if (lowLink[nbr] > lowLink[u])
                cout<<u<<" --- "<<nbr<<"\n";
        } else {
            lowLink[u] = min(lowLink[u], in[nbr]);
        };
    };

};

void findArticulationPoints(int u, SimpleGraph<int> &graph, vector<int> &in, vector<int> &lowLink, set<int> &visited, set<int> &cutPoints, int &time, int parent) {

    in[u] = lowLink[u] = time++;
    visited.insert(u);

    int children = 0;

    for (int x = 0; x < graph.getVertexEdges(u).size(); x++) {
        int nbr = graph.getVertexEdges(u)[x];
        if (nbr == parent) continue;

        if (!visited.count(nbr)) {
            findArticulationPoints(nbr, graph, in, lowLink, visited, cutPoints, time, u);
            lowLink[u] = min(lowLink[u], lowLink[nbr]);
            if (lowLink[nbr] >= lowLink[u] && u != parent && !cutPoints.count(u)) {
                cout << u << " IS A CUTPOINT!\n";
                cutPoints.insert(u);
            };

            children++;
        } else {
            lowLink[u] = min(lowLink[u], in[nbr]);
        };
    };

    if (u == parent && children > 1 && !cutPoints.count(u)) {
        cout << u << " IS A CUTPOINT!\n";
        cutPoints.insert(u);
    };

};

int main () {
    SimpleGraph<int> g(true);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(5, 7);
    g.addEdge(7, 8);
    g.addEdge(7, 9);

    set<int> vertices = g.getVertices();
    set<int>::iterator it = vertices.begin();

    int time = 0;
    vector<int> in(vertices.size(), UNVISITED);
    vector<int> lowLink(vertices.size(), UNVISITED);
    set<int> visited;
    cout<<"Bridges:";
    cout << "\n========\n\n";
    while (it != vertices.end()) {
        findBridges(*it, g, in, lowLink, visited, time, *it);
        it++;
    };
    
    cout << "\n========\n";

    visited.clear();
    it = vertices.begin();
    time = 0;

    for (int x = 0; x < vertices.size(); x++)
        in[x] = lowLink[x] = UNVISITED;

    cout << "\n========\n\n";
    set<int> cutPoints;
    while (it != vertices.end()) {
        findArticulationPoints(*it, g, in, lowLink, visited, cutPoints, time, *it);
        it++;
    }

    cout << "\n========\n\n";

    return 0;
};