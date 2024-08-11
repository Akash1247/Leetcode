class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
    if (isDisconnected(grid)) return 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1) {
          grid[i][j] = 0;
          if (isDisconnected(grid)) return 1;
          grid[i][j] = 1;
        }
      }
    }
    return 2;
  }
private:
  const vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  bool isDisconnected(const vector<vector<int>>& grid) {
    int islands = 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1 && !visited[i][j]) {
          if (++islands > 1) return true;
          dfs(grid, i, j, visited);
        }
      }
    }
    return islands != 1;
  }
  void dfs(const vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited) {
    visited[x][y] = true;
    for (const auto& [dx, dy] : directions) {
      int newX = x + dx, newY = y + dy;
      if (isValid(grid, newX, newY) && grid[newX][newY] == 1 && !visited[newX][newY]) {
        dfs(grid, newX, newY, visited);
      }
    }
  }
  bool isValid(const vector<vector<int>>& grid, int x, int y) {
    return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
  }
};