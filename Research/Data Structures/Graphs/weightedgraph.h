#include <bits/stdc++.h>

// More to be added, however this was made for Kruskal's MST Algorithm quickly. Yes, a lot is missing.
class WeightedGraph {
    public:
        // Initializes the Weighted Graph. Takes in the vertices, and if it is directed.
        WeightedGraph(vector<string> &vertices, bool isDirected) {
            V = vertices.size();
            directed = isDirected;

            // Adds the vertices to the an adjacency list implemented with a hashmap, and initializes the list.
            // Also stores the vertexes locally in the class for retrieval.
            for (int x = 0; x < V; x++) {
                g[vertices[x]] = vector<pair<string, int> >();
                verts.push_back(vertices[x]);
            };
        };

        // Adds edges between existing vertices, along with a weight.
        void addEdge(string u, string v, int w) {
            // Checks if both vertexes are in the graph. If any of them are not in the graph, add them.
            if (!g.count(u)) addVertex(u);
            if (!g.count(v)) addVertex(v);

            // Create an edge. If the graph is undirected, add another edge in reverse.
            g[u].push_back(make_pair(v, w));
            if (!directed) g[v].push_back(make_pair(u, w));

        };

        // Adds a vertex if it was not in the graph.
        void addVertex(string v) {
            if (g.count(v)) return;

            // Initializes the adjacency list for edges.
            // Adds the new vertex to the list of vertices.
            // Increases the number of vertices in the graph.
            g[v] = vector<pair<string, int> >();
            verts.push_back(v);
            V++;
        };

        // Returns the unique edges in the graph.
        // The only time there can be non unique edges are with undirected graphs.
        vector<pair<pair<string, string>, int> > getUniqueEdges() {
            
            // Initialize a set to keep track of added edges.
            set<pair<string, string> > added;

            // Initializes the return array
            vector<pair<pair<string, string>, int> > uniqueEdges;

            // Starts an iterator at the beginning of the graph adjacency list map.
            map<string, vector<pair<string, int> > >::iterator it = g.begin();

            // Iterate through all the edges...
            while (it != g.end()) {
                string u = (*it).first;
                for(int x = 0; x < (*it).second.size(); x++) {
                    pair<string, int> v = (*it).second[x];

                    // Checks if the edge or an alternative orientation has not been added already.
                    if (!added.count(make_pair(u, v.first)) && !added.count(make_pair(v.first, u))) {
                        // Adds it to the set for possible future overlap
                        // Pushses the set into the return array.
                        added.insert(make_pair(u, v.first));
                        uniqueEdges.push_back(make_pair(make_pair(u,v.first), v.second));
                    };
                };

                it++;
            };

            // Returns the uniqueEdges.
            return uniqueEdges;
        };

        // Returns the number of vertices in the graph.
        unsigned int numVertices() { return V; };
        
        // Returns the vertices in the graph.
        vector<string> getVertices() { return verts; };

    private:
        unsigned int V;
        bool directed;
        map<string, vector<pair<string, int> > > g;
        vector<string> verts;

};