#include<bits/stdc++.h>
using namespace std;

/*

Approach: Regular dfs tree

*/

void dfs(int u, vector<vector<int>> &rooms, unordered_set<int> &visited) {
    visited.insert(u);
    for (auto v: rooms[u])
        if (!visited.count(v))
            dfs(v, rooms, visited);
};

bool canVisitAllRooms(vector<vector<int>> rooms) {
    unordered_set<int> visited;
    dfs(0, rooms, visited);
    return visited.size()==rooms.size();
};