#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    DSU dsu(n * n);
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    // Store cells as (value, x, y)
    vector<pair<int, pair<int, int>>> cells;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cells.push_back({grid[i][j], {i, j}});

    // Sort cells in ascending order based on water level
    sort(cells.begin(), cells.end());

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int index = 0;

    for (auto& cell : cells) {
        int time = cell.first, x = cell.second.first, y = cell.second.second;
        visited[x][y] = true;

        // Try to merge with neighboring cells
        for (auto& dir : directions) {
            int nx = x + dir[0], ny = y + dir[1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && visited[nx][ny]) {
                dsu.unite(x * n + y, nx * n + ny);
            }
        }

        // Check if start (0,0) and end (n-1,n-1) are connected
        if (dsu.find(0) == dsu.find(n * n - 1)) {
            return time;
        }
    }

    return -1; // Should never reach here
}

int main() {
    vector<vector<int>> grid = {
        {0, 2, 1, 3},
        {3, 2, 5, 4},
        {6, 7, 8, 9},
        {12, 10, 11, 13}
    };
    cout << "Minimum time to swim: " << swimInWater(grid) << endl;
    return 0;
}
