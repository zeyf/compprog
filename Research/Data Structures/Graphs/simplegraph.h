#include <bits/stdc++.h>
using namespace std;

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