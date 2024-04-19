class Solution {
public:
  int dfs(int y, int x, vector<vector<int>> &grid, vector<vector<bool>> &chk) {
    if (y < 0 || y >= grid.size() || x < 0 || x >= grid[0].size() ||
        0 == grid[y][x] || true == chk[y][x]) {
      return 0;
    }
    chk[y][x] = true;
    return dfs(y - 1, x, grid, chk) + dfs(y + 1, x, grid, chk) +
           dfs(y, x - 1, grid, chk) + dfs(y, x + 1, grid, chk) + 1;
  }

  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> chk(n, vector<bool>(m, false));
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (0 == grid[i][j] || true == chk[i][j]) {
          continue;
        }
        ans = max(dfs(i, j, grid, chk), ans);
      }
    }
    return ans;
  }
};
