class Solution {
public:
  int res = 0;
  int idx = 0;

  void dfs(vector<vector<int>> &v, int cnt, int c, int l) {
    if (idx == cnt) {
      res = max(res, c);
      return;
    }
    for (int i = 0; i < v.size(); i++) {
      if ((cnt & (1 << i)) != 0)
        continue;
      int p = cnt + (1 << i);
      int k = c + v[l][i];
      dfs(v, p, k, l + 1);
    }
  }

  int maxCompatibilitySum(vector<vector<int>> &students,
                          vector<vector<int>> &mentors) {
    int n = students.size();
    for (int i = 0; i < n; i++)
      idx += (1 << i);
    int m = students[0].size();
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int t = 0;
        for (int k = 0; k < m; k++) {
          t += (students[i][k] == mentors[j][k]);
        }
        v[i][j] = t;
      }
    }
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      cnt += (1 << i);
      int c = 0;
      c += v[0][i];
      int l = 1;
      dfs(v, cnt, c, l);
    }
    return res;
  }
};
