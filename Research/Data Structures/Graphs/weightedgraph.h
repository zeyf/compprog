#include <bits/stdc++.h>

template<typename T>
class WeightedGraph {

public:
    WeightedGraph(bool undir);

    void addEdge(T u, T v, int w) {
        adjlist[u].push_back(make_pair(w,v));
        if (undirected) adjlist[v].push_back(make_pair(w,u));
        vertices.insert(u); vertices.insert(v);
    };

    unordered_set<T> getVertices() {
        return vertices;
    };

    vector<pair<int, T> > getVertexEdges(T u) {
        return adjlist[u];
    }

private:
    unordered_map<T, vector<pair<int, T> > > adjlist;
    unordered_set<T> vertices;
    bool undirected;

};

template <typename T>
WeightedGraph<T>::WeightedGraph(bool undir) {
    undirected = undir;
    vertices = unordered_set<T>();
};