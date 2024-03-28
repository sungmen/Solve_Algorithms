class Solution {
public:
  double cal(vector<int> x, vector<int> y, vector<int> z) {
    return abs((x[0] * y[1]) + (y[0] * z[1]) + (z[0] * x[1]) - (y[0] * x[1]) -
               (z[0] * y[1]) - (x[0] * z[1])) /
           (double)2;
  }
  double largestTriangleArea(vector<vector<int>> &points) {
    int n = points.size();
    double ans = 0.0;
    for (int i = 0; i < n - 2; i++) {
      for (int j = i + 1; j < n - 1; j++) {
        for (int k = j + 1; k < n; k++) {
          ans = max(ans, cal(points[i], points[j], points[k]));
        }
      }
    }
    return ans;
  }
};
