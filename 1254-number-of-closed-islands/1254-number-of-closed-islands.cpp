class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Out of bounds or if it's water (1) or already visited (marked as 1)
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 1) return;
        
        // Mark current land (0) as visited by turning it into water (1)
        grid[i][j] = 1;
        
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        
        // Step 1: Flood-fill all land cells connected to the boundary (they can't be closed islands)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && grid[i][j] == 0) {
                    dfs(grid, i, j);
                }
            }
        }
        
        // Step 2: Count remaining isolated components of 0s
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};