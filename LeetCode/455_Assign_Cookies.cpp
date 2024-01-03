class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int idx = s.size() - 1;
    int ans = 0;
    for (int i = g.size() - 1; i >= 0; i--) {
      if (idx == -1)
        return ans;
      if (g[i] <= s[idx]) {
        idx--;
        ans++;
      }
    }
    return ans;
  }
};
