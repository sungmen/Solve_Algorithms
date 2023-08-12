class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
    vector<vector<int>> ans(r, vector<int>(c));
    int m = mat.size(), n = mat[0].size(), y1 = 0, x1 = 0, y2 = 0, x2 = 0,
        cnt = 0;
    if (r * c != m * n)
      return mat;
    while (cnt < m * n && cnt < r * c) {
      ans[y2][x2] = mat[y1][x1];
      x2++;
      x1++;
      if (x2 == c) {
        x2 = 0;
        y2++;
      }
      if (x1 == n) {
        x1 = 0;
        y1++;
      }
      cnt++;
    }
    return ans;
  }
};
