class Solution {
public:
    int m, n;
    
    // DFS to explore an island
    bool dfs(vector<vector<int>>& grid, int i, int j) {
        // If out of bounds → this island touches boundary → not closed
        if (i < 0 || j < 0 || i >= m || j >= n) return false;
        
        // If water, stop exploring
        if (grid[i][j] == 1) return true;
        
        // Mark visited (turn land into water)
        grid[i][j] = 1;
        
        // Explore all 4 directions
        bool up = dfs(grid, i - 1, j);
        bool down = dfs(grid, i + 1, j);
        bool left = dfs(grid, i, j - 1);
        bool right = dfs(grid, i, j + 1);
        
        // Island is closed only if all four directions are valid (true)
        return up && down && left && right;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    // Start DFS and check if island is closed
                    if (dfs(grid, i, j)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
