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

    /*
    When first getting to a node, the in time and the lowest link of that node are the current time. The time has to be increased for possible further nodes that will be processed.
    Insert the current node into the visited set.
    */
    in[u] = lowLink[u] = time++;
    visited.insert(u);

    // iterate through the edges of a given node in the graph
    for (int x = 0; x < graph.getVertexEdges(u).size(); x++) {
        // get the current neighbor
        int nbr = graph.getVertexEdges(u)[x];

        // we do not want to consider the immediate parent of the current node.
        if (nbr == parent) continue;

        // if we have not visited the node
        if (!visited.count(nbr)) {

            // DFS, to find out and if there is a lower lowLink edge from a descendant of u than u itself. Be greedy, take the lowest possible.
            findBridges(nbr, graph, in, lowLink, visited, time, u);

            // If a descendant of u has a backedge to an ancestor of u or u itself, take the minimum of it's lowlinks.
            lowLink[u] = min(lowLink[u], lowLink[nbr]);

            /*
            This step differs slightly from that of the articulation points algorithm, in that we do not consider the == case on the comparison
            The reason we do not consider the == case on the comparison is because by definition,
            bridges are where disconnecting the edge between u and nbr increases the number of connected components.
            If the lowLink[nbr] == lowLink[u], this means that there is a descendant of current node u that connects to u aside from the current neighbor nbr.
            This means that removing this edge will NOT result in a bridge as there is another path to it -- meaning a back edge to u itself exists, aside from that of u and nbr (parents not considered)
            So if the only way to get to nbr and it's descendants is through the u--nbr edge, then we have a bridge.
            */
            if (lowLink[nbr] > in[u])
                cout<<u<<" --- "<<nbr<<"\n";
        } else {
            // If we have already visited this node, this means we are at a backedge, meaning take the minimum of the current node lowLink and the visited neighbor's in time.
            // Note: backedges will never be bridges!
            lowLink[u] = min(lowLink[u], in[nbr]);
        };
    };

};

void findArticulationPoints(int u, SimpleGraph<int> &graph, vector<int> &in, vector<int> &lowLink, set<int> &visited, set<int> &cutPoints, int &time, int parent) {

    /*
    When first getting to a node, the in time and the lowest link of that node are the current time. The time has to be increased for possible further nodes that will be processed.
    Insert the current node into the visited set.
    */
    in[u] = lowLink[u] = time++;
    visited.insert(u);

    /*
    This is a little less intuitive to understand but...
    To account for the number of disjoint subtrees that the neighbors of the root are, we count children.
    For example:
    If we have a graph: 1-2, 2-3, 3-4, 4-1 (it is just a connected diamond)
    We are at the root, so the children count is relevant in the case that the root is a cut point.
    The edge 1--2 will count as a child, because 2 is unvisited. However, we will then get to 4, which has an edge 4-1.
    When we are done and come back up to the recursive call of 1 (the root), we will then NOT go to 4 from the 4-1 edge as it was visited.
    The fact that from 1 there was another node that connects to 1 in this graph was found means that we will count 1 child. In that case, cutting out 1 will not result in more connected components.

    However if we have a graph 1-2, 2-3, 4-1
    The 1-2 edge will count as one child, and then when getting to the 4-1 edge from 1, 4 is unvisited, meaning we do not have any other link to that node aside from the root.
    Meaning we have 2 children at the root. If the root has more than one child, we have (excluding the root), two connected components.
    Therefore, the root is a cut point itself.
    */
    int children = 0;

    // iterate through the edges of a given node in the graph
    for (int x = 0; x < graph.getVertexEdges(u).size(); x++) {
        // get the current neighbor
        int nbr = graph.getVertexEdges(u)[x];

        // we do not want to consider the immediate parent of the current node.
        if (nbr == parent) continue;

        // if we have not visited the node
        if (!visited.count(nbr)) {

            // DFS, to find out and if there is a lower lowLink edge from a descendant of u than u itself. Be greedy, take the lowest possible.
            findArticulationPoints(nbr, graph, in, lowLink, visited, cutPoints, time, u);

            // If a descendant of u has a backedge to an ancestor of u or u itself, take the minimum of it's lowlinks.
            lowLink[u] = min(lowLink[u], lowLink[nbr]);

            /*
            This step differs slightly from the bridge algorithm because:
            We have an edge case of the root considering we are examining vertices instead of edges between vertices, and the obvious difference between art points and bridges.
            Bridges imply art points, but art points do not imply bridges.

            If we find a neighbor with a lowLink that is greater than or equal to the current node,
            this means that the only way to get to all descendants of the current node is through the current node.
            So, if we are not the root and we haven't added the cutPoint, print and insert it into the cutPoint set.
            The edge case that u != parent makes sense in conjunction with the lowLink[nbr] >= lowLink[u] condition...
            The reason it makes sense is because since the smallest time will always be the root of the DFS tree, without this condition
            The root would ALWAYS be included as a cut point despite possibly not being one...
            The root is accounted for based on the disconnected components (children) it has...
            */
            if (lowLink[nbr] >= in[u] && u != parent && !cutPoints.count(u)) {
                cout << u << " IS A CUTPOINT!\n";
                cutPoints.insert(u);
            };

            // We just processed an unvisited neighbor! Increment this a "child", but more like connected component.
            children++;
        } else {
            // If we have already visited this node, this means we are at a backedge, meaning take the minimum of the current node lowLink and the visited neighbor's in time.
            lowLink[u] = min(lowLink[u], in[nbr]);
        };
    };

    // The only time u == parent will be at the root. If we find more than one child aka connected component from the root, we add it in.
    // Since we only see the root once, this will only be possible where u==parent once.
    if (u == parent && children > 1) {
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