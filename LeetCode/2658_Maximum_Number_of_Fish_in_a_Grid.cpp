class Solution {
public:
  int dfs(vector<vector<int>> &grid, int y, int x) {
    if (y < 0 || y >= grid.size() || x < 0 || x >= grid[0].size() ||
        0 == grid[y][x])
      return 0;
    int sum = grid[y][x];
    grid[y][x] = 0;
    return sum + dfs(grid, y + 1, x) + dfs(grid, y - 1, x) +
           dfs(grid, y, x + 1) + dfs(grid, y, x - 1);
  }

  int findMaxFish(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (0 == grid[i][j])
          continue;
        ans = max(ans, dfs(grid, i, j));
      }
    }
    return ans;
  }
};
