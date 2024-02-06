class Solution {
public:
  int oddCells(int m, int n, vector<vector<int>> &indices) {
    vector<vector<int>> v(m, vector<int>(n, 0));
    for (auto indice : indices) {
      for (int i = 0; i < n; i++)
        v[indice[0]][i]++;
      for (int i = 0; i < m; i++)
        v[i][indice[1]]++;
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (v[i][j] % 2)
          cnt++;
      }
    }
    return cnt;
  }
};
