#include<bits/stdc++.h>
using namespace std;

// Check if the current proposed location is inbounds
bool inbounds(int n, int m, int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
};

// This has a lot of moving parts.
/*
    The idea behind this function is to merge results from multiple heuristics:
    - The currentComponentVisited set
    - the globalVisited set
    - the intime grid
    - the parent X and parent Y value of the current X, Y

    The current component visited backtracks visitation to attempt all possible paths through a connected component
    The intime will also be reset and technically will be backtracked by just being overwritten.
    The global visited is so just in case a cycle is not found in the current component, we can not traverse an already visited connected component again.

    When a backedge is found, we must check if the intime of the two nodes,
    the current and the ancestor of the current + 1 (to account for the backedge) is greater than or equal to 4, which was one requisite of a cycle here.
*/
bool dfs(vector<vector<char> > &grid, set<pair<int, int> > & currentComponentVisited, set<pair<int, int> > &globalVisited, vector<vector<int> > &intime, int x, int y, int px, int py, int timer = 1) {

    // visit in current and global, also mark in time
    int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 };
    currentComponentVisited.insert(make_pair(x,y));
    globalVisited.insert(make_pair(x,y));
    intime[x][y] = timer;

    // iterate all directions
    for (int z = 0; z < 4; ++z) {
        int nr = x + dx[z], nc = y + dy[z];

        // if the neighbor is the parent of current...
        if (nr == px && nc == py) continue;

        // if the next location is inbounds and of the same color
        if (inbounds(grid.size(), grid[0].size(), nr, nc) && grid[nr][nc] == grid[x][y]) {

            // if this next location is not visited in our currentComponentVisited traversal...
            if (!currentComponentVisited.count(make_pair(nr,nc))) {
                // perform a DFS. If this sub result is true, we have found a qualifying cycle.
                if (dfs(grid, currentComponentVisited, globalVisited, intime, nr, nc, x, y, timer + 1))
                    return true;
            
            // if this next location is visite din our currentComponentVisited traversal
            } else {
                // the current and the ancestor of the current + 1 (to account for the backedge) is greater than or equal to 4, return true.
                // we have found a qualifying cycle via backedge and intime.
                if ((abs(intime[nr][nc] - intime[x][y]) + 1) >= 4)
                    return true;
            };
        };
    };

    // backtrack.
    currentComponentVisited.erase(make_pair(x,y));
    return false;
};

bool containsCycle(vector<vector<char> > grid) {
    // initialize the sets and the intime grid.
    set<pair<int, int> > currentComponentVisited, globalVisited;
    vector<vector<int> > intime(grid.size(), vector<int>(grid[0].size(), 0));

    // iterate through the grid...
    for (int x = 0; x < grid.size(); ++x)
        for (int y = 0; y < grid[x].size(); ++y)
            // if the location is unvisited globally, we have not processed the connected component.
            // if we have not visited this globally and the dfs result is true, we have a qualifying cycle in this component. Return true.
            if (!globalVisited.count(make_pair(x,y)) && dfs(grid, currentComponentVisited, globalVisited, intime, x, y, x, y, 1))
                return true;
    
    // we have not found any qualifying cycle in the entire graph. Return false.
    return false;
};

/*

Needed:
- Two sets... one for current traversal, one for overall traversal.
- in time grid to track intime for cycle detection.
- inbounds function to check if a location is valid or not.
- check for same color value if a cell location is inbounds.
The current traversal set will be used for the same color value.
The overall traversal will be used for to not search over searched area.
The current traversal set will be backtracking visitation after processing subtrees.

Step 1: Traverse the graph left to right.
Step 2: If not visited in overall visited set, dfs into same color adjacent.
Step 3: DFS tree backtrack, track intime with counter, color and backtrack current set, but just color for overall set.
Step 4: If a backedge is found with an intime difference from a node u to v >= 4, return true. Store this and return the result. Do not backtrack this if found, we want to color the overall same color component. Be greedy and take any cycle if found though.
Step 5: If a cycle was found, return true.
Step 6: If after going through the graph no cycle was found, return false.

*/