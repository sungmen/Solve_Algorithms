class Solution {
public:
  int dfs(string &s, int left, int right, int res,
          map<pair<int, int>, int> &m) {
    if (left >= right) {
      return 0;
    }
    if (m.find({left, right}) != m.end()) {
      return m[{left, right}];
    }
    if (s[left] == s[right]) {
      m[{left, right}] = dfs(s, left + 1, right - 1, res, m);
    } else {
      m[{left, right}] = min(dfs(s, left + 1, right, res + 1, m),
                             dfs(s, left, right - 1, res + 1, m)) +
                         1;
    }
    return m[{left, right}];
  }

  int minInsertions(string s) {
    int ans = 1e9;
    map<pair<int, int>, int> m;

    return dfs(s, 0, s.size() - 1, 0, m);
    ;
  }
};
