class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int ans = 0;
    vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
      v[i][1] = matrix[i - 1][0] + v[i - 1][1];
    for (int i = 1; i <= m; i++)
      v[1][i] = matrix[0][i - 1] + v[1][i - 1];
    for (int i = 2; i <= n; i++) {
      for (int j = 2; j <= m; j++) {
        v[i][j] =
            v[i][j - 1] + v[i - 1][j] - v[i - 1][j - 1] + matrix[i - 1][j - 1];
      }
    }
    for (int y2 = 1; y2 <= n; y2++) {
      for (int x2 = 1; x2 <= m; x2++) {
        for (int y1 = 1; y1 <= y2; y1++) {
          for (int x1 = 1; x1 <= x2; x1++) {
            int cur =
                v[y2][x2] - v[y1 - 1][x2] - v[y2][x1 - 1] + v[y1 - 1][x1 - 1];
            if (cur == target) {
              ans++;
            }
          }
        }
      }
    }

    return ans;
  }
};
