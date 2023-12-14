class Solution {
public:
  int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<int> row(n);
    vector<int> col(m);
    unordered_map<int, pair<int, int>> um;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        um[mat[i][j]] = {i, j};
      }
    }
    int ans = 0;
    for (auto it : arr) {
      pair<int, int> cur = um[it];
      row[cur.first]++;
      col[cur.second]++;
      if (row[cur.first] == m || col[cur.second] == n)
        return ans;
      ans++;
    }
    return 0;
  }
};
