class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int initialColor, int newColor) {
        int m = image.size();
        int n = image[0].size();
        
        // Check boundaries
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        
        // If the color is not the same as the initial color, stop
        if (image[i][j] != initialColor) return;
        
        // Change the color
        image[i][j] = newColor;
        
        // Visit 4-directionally (up, down, left, right)
        dfs(image, i + 1, j, initialColor, newColor);
        dfs(image, i - 1, j, initialColor, newColor);
        dfs(image, i, j + 1, initialColor, newColor);
        dfs(image, i, j - 1, initialColor, newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if (initialColor == color) return image; // No need to change
        
        dfs(image, sr, sc, initialColor, color);
        return image;
    }
};
