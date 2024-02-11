class Solution {
public:
  int findChampion(vector<vector<int>> &grid) {
    int n = grid.size();
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int t = 0;
      for (int j = 0; j < n; j++) {
        if (1 == grid[i][j])
          t++;
      }
      if (cnt < t) {
        cnt = t;
        ans = i;
      }
    }
    return ans;
  }
};
