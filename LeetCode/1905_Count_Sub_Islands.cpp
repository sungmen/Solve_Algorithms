class Solution {
public:
  int n = 0;
  int m = 0;

  bool dfs(int y, int x, vector<vector<int>> &grid, vector<vector<bool>> &chk,
           vector<vector<int>> &comp) {
    if (y < 0 || y >= n || x < 0 || x >= m || 0 == grid[y][x] ||
        true == chk[y][x]) {
      return true;
    }
    chk[y][x] = true;
    bool res = (1 == comp[y][x]);
    return res & dfs(y - 1, x, grid, chk, comp) &
           dfs(y + 1, x, grid, chk, comp) & dfs(y, x - 1, grid, chk, comp) &
           dfs(y, x + 1, grid, chk, comp);
  }

  int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
    n = grid1.size();
    m = grid1[0].size();
    int ans = 0;

    vector<vector<bool>> chk(n, vector<bool>(m));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (0 == grid2[i][j] || true == chk[i][j]) {
          continue;
        }
        ans += (dfs(i, j, grid2, chk, grid1) ? 1 : 0);
      }
    }
    return ans;
  }
};
