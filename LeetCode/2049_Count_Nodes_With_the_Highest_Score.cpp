class Solution {
public:
  int dfs(vector<vector<int>> &child, vector<int> &count, int idx) {
    int cnt = 1;
    for (auto i : child[idx]) {
      cnt += dfs(child, count, i);
    }
    count[idx] = cnt;
    return cnt;
  }

  int countHighestScoreNodes(vector<int> &parents) {
    int n = parents.size();
    vector<vector<int>> child(n);
    vector<int> count(n, 0);
    for (int i = 0; i < parents.size(); i++) {
      if (-1 == parents[i])
        continue;
      child[parents[i]].push_back(i);
    }
    dfs(child, count, 0);
    unordered_map<long long, int> um;
    long long result = 0;
    for (int i = 0; i < n; i++) {
      long long cnt = (0 != count[0] - count[i] ? count[0] - count[i] : 1);
      for (auto j : child[i]) {
        cnt *= count[j];
      }
      um[cnt]++;
      if (result < cnt) {
        result = cnt;
      }
    }
    return um[result];
  }
};
