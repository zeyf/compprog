#include <bits/stdc++.h>
using namespace std;

#define loop(s,e) for(int x = s; x < e; x++)

// TO VIEW THE COMMENTED, UPDATED VERSION, GO TO Union Find/unionfind.h
// Disjoint Set / Union Find data structure
class UnionFind {
	public:
		UnionFind(unsigned int size) { init(size); };

		int find(int u) {
			if (u == sets[u]) return u;
			return (sets[u] = find(sets[u]));
		};

		bool uni(int u, int v) {
			int uSet = find(u), vSet = find(v);
			if (uSet == vSet) return false;
			
			if (cards[uSet] > cards[vSet]) {
				cards[uSet] += cards[vSet];
				cards[vSet] = 0;
				sets[vSet] = uSet;
			} else {
				cards[vSet] += cards[uSet];
				cards[uSet] = 0;
				sets[uSet] = vSet;
			};

			numComponents--;
			return true;
		};
		
		bool sameSet(int u, int v) {
			return find(u) == find(v);
		};

		unsigned int getSetsCount() { return numComponents; };
		int getSetSize(int u) { return cards[find(u)]; };

        void showState() { loop(0, n) cout << sets[x] << " "; cout << "\n"; };

	private:
		unsigned int n, numComponents;
		// sets with respective cardinalities
		vector<int> sets, cards;
		void init(unsigned int size) {
			n = numComponents = size;
			sets = vector<int>(size);
			cards = vector<int>(size);
			loop(0,n) {
				sets[x] = x;
				cards[x] = 1;
			};
		};

};

// TO VIEW THE COMMENTED, UPDATED VERSION, GO TO Graphs/weightedgraph.h
// Weighted Graph (directed/undirected supported)
class WeightedGraph {
    public:
        WeightedGraph(vector<string> &vertices, bool isDirected) {
            V = vertices.size();
            directed = isDirected;
            loop(0,V) {
                g[vertices[x]] = vector<pair<string, int> >();
                verts.push_back(vertices[x]);
            };
        };

        void addEdge(string u, string v, int w) {
            g[u].push_back(make_pair(v, w));
            if (!directed) g[v].push_back(make_pair(u, w));
        };

        vector<pair<pair<string, string>, int> > getUniqueEdges() {
            set<pair<string, string> > added;
            vector<pair<pair<string, string>, int> > uniqueEdges;

            map<string, vector<pair<string, int> > >::iterator it = g.begin();
            while (it != g.end()) {
                string u = (*it).first;
                loop(0, (*it).second.size()) {
                    pair<string, int> v = (*it).second[x];
                    if (!added.count(make_pair(u, v.first)) && !added.count(make_pair(v.first, u))) {
                        added.insert(make_pair(u, v.first));
                        uniqueEdges.push_back(make_pair(make_pair(u,v.first), v.second));
                    };
                };

                it++;
            };

            return uniqueEdges;
        };

        unsigned int numVertices() { return V; };
        vector<string> getVertices() { return verts; };

    private:
        unsigned int V;
        bool directed;
        map<string, vector<pair<string, int> > > g;
        vector<string> verts;

};

// comparator to sort edges by weight in ascending order
bool weightedEdgeComparator(pair<pair<string, string>, int> a, pair<pair<string, string>, int> b) {
    return b.second > a.second;
};

// runs Kruskal's MST with Disjoint Set / Union Find data structure.
void kruskal(vector<pair<pair<string, string>, int> >& edges, WeightedGraph &graph) {

    // Step 1: Sort the edges
    sort(edges.begin(), edges.end(), weightedEdgeComparator);

    // Step 2: Create your Union Find of size = number of vertices
    UnionFind uf = UnionFind(graph.numVertices());

    // Step 3: have all vertices, and use a hashmap to map them to a given index in the Disjoint Set / Union Find data structure
    vector<string> vertices = graph.getVertices();
    map<string, unsigned int> vertexMap;
    loop(0, vertices.size()) vertexMap[vertices[x]] = x;

    // Track cost of the edges and edges added
    int cost = 0, MSTEdgeCount = 0;

    // Print the initial state of the Union Find (for visual purposes)
    uf.showState();

    // Step 4: Iterate through the sorted edges
    loop(0, edges.size()) {
        pair<pair<string, string>, int> uvw = edges[x];
        string u = uvw.first.first, v = uvw.first.second;
        int w = uvw.second;

        // Step 5: Check if adding a link from u to v creates a cycle (same set)
        // if node u and node v do not belong to the same set (different parent roots)
        // add the edge, we can keep up the acyclic property of trees with this edge.
        if (uf.uni(vertexMap[u], vertexMap[v])) {
            // add the cost of the edge
            // increment the edge count, we just took it.
            cost += w;
            MSTEdgeCount++;
        };

        // Show the state of a possible state change
        uf.showState();
        
        // if we fullfill the property of a tree being for v vertices, v-1 edges
        if (MSTEdgeCount == vertexMap.size()-1)
            break;
    };

    cout << "FINAL COST: " << cost << "\n";
};


int main () {

    vector<string> vertices;
    vertices.push_back("Miami");
    vertices.push_back("Fort Myers");
    vertices.push_back("Key West");
    vertices.push_back("Naples");
    vertices.push_back("Orlando");
    vertices.push_back("Jacksonville");
    vertices.push_back("Tallahassee");
    vertices.push_back("Destin");

    WeightedGraph g = WeightedGraph(vertices, false);
    g.addEdge("Miami", "Key West", 5);
    g.addEdge("Miami", "Orlando", 10);
    g.addEdge("Miami", "Naples", 20);
    g.addEdge("Naples", "Fort Myers", 3);
    g.addEdge("Naples", "Orlando", 6);
    g.addEdge("Naples", "Jacksonville", 12);
    g.addEdge("Orlando", "Jacksonville", 4);
    g.addEdge("Fort Myers", "Jacksonville", 10);
    g.addEdge("Tallahassee", "Jacksonville", 20);
    g.addEdge("Destin", "Tallahassee", 4);

    vector<pair<pair<string, string>, int> > uniqueEdges = g.getUniqueEdges();
    kruskal(uniqueEdges, g);

    return 0;
};