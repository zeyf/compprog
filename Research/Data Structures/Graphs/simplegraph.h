#include <bits/stdc++.h>
using namespace std;

template<typename T>
class SimpleGraph {

public:
    SimpleGraph(bool undir);

    void addEdge(T u, T v) {
        adjlist[u].push_back(v);
        if (undirected) adjlist[v].push_back(u);

        vertices.insert(u); vertices.insert(v);
    };

    unordered_set<T> getVertices() {
        return vertices;
    };

    vector<T> getVertexEdges(T u) {
        return adjlist[u];
    }

private:
    unordered_map<T, vector<T> > adjlist;
    unordered_set<T> vertices;
    bool undirected;

};

template <typename T>
SimpleGraph<T>::SimpleGraph(bool undir) {
    undirected = undir;
    vertices = unordered_set<T>();
};