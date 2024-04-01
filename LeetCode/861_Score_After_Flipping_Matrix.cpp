class Solution {
public:
  int matrixScore(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++) {
      if (1 == grid[i][0])
        continue;
      for (int j = 0; j < m; j++) {
        grid[i][j] ^= 1;
      }
    }
    int c = m - 1;
    int ans = (1 << c--) * n;
    for (int i = 1; i < m; i++) {
      int z = 0;
      int o = 0;
      for (int j = 0; j < n; j++) {
        if (1 == grid[j][i])
          o++;
        else
          z++;
      }
      ans += (1 << c--) * max(z, o);
    }
    return ans;
  }
};
