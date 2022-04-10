#include<bits/stdc++.h>
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

bool validBfs(int n, vector<int> sequence , vector<vector<int>> edges) {

    map<int, vector<int>> graph;
    int x;
    range(0, edges.size(), 1, x) {
        vector<int> edge = edges[x];
        if (!graph.count(edge[0]))
            graph[edge[0]] = vector<int>();
        if (!graph.count(edge[1]))
            graph[edge[1]] = vector<int>();
        
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    };

    // invalid sequence, either more values or less values than vertexes!
    if (graph.size() != sequence.size()) return false;

    queue<int> q;
    set<int> visited;
    q.push(1);
    visited.insert(1);

    int ptr = 0;

    while (!q.empty()) {
        int size = q.size();
        map<int, int> level;

        int end = ptr+size;
        range(ptr, end, 1, x) {
            if (!level.count(sequence[x])) level[sequence[x]] = 1;
            else level[sequence[x]]++;
            ptr++;
        };

        while (size--) {
            int c = q.pop();
            if (!level.count(c))
                return false;
            else if (level[c] == 0)
                return false;
            level[c]--;

            for (int &nbr: graph[c]) {
                if (!visited.count(nbr)) {
                    visited.insert(nbr);
                    q.push(nbr);
                };
            };
        };

        map<int, int>::iterator it = level.begin();
        while (it != level.end()) {
            if ((*it).second > 0)
                return false;
            it++;
        };

    };


    return ptr == sequence.size();
}