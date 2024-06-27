class Solution {
public:
  int largestSubmatrix(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    for (int j = 0; j < n; j++) {
      for (int i = 1; i < m; i++) {
        if (0 == matrix[i][j]) {
          continue;
        }
        matrix[i][j] += matrix[i - 1][j];
      }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
      sort(matrix[i].begin(), matrix[i].end(), std::greater<>());
      int k = matrix[i][0];
      for (int j = 0; j < n; j++) {
        k = min(k, matrix[i][j]);
        ans = max(ans, k * (j + 1));
      }
    }
    return ans;
  }
};
