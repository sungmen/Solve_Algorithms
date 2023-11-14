class Solution {
public:
  int countPalindromicSubsequence(string s) {
    vector<vector<int>> v(26, vector<int>());
    for (int i = 0; i < s.size(); i++) {
      v[s[i] - 'a'].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
      if (v[i].size() < 2)
        continue;
      if (v[i].size() >= 3)
        ans++;
      for (int j = 0; j < 26; j++) {
        if (i == j || 0 == v[j].size())
          continue;
        auto it = lower_bound(v[j].begin(), v[j].end(), v[i][0]);
        if (it == v[j].end() || v[j][it - v[j].begin()] > v[i][v[i].size() - 1])
          continue;
        ans++;
      }
    }
    return ans;
  }
};
