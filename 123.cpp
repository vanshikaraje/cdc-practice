#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        // Boundary + water check
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0')
            return;

        // Mark as visited
        grid[i][j] = '0';

        // Explore 4 directions (up, down, left, right)
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;          // Found a new island
                    dfs(grid, i, j);  // Mark the whole island
                }
            }
        }

        return count;
    }
};

// For local testing in VS Code
int main() {
    Solution sol;
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << "Number of islands: " << sol.numIslands(grid) << endl;
    return 0;
}
