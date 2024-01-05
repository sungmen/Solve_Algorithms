class Solution {
public:
  int longestIdealString(string s, int k) {
    int dp[26] = {
        0,
    };
    int res = 0;
    for (auto c : s) {
      int t = c - 'a';
      for (int i = (t - k < 0 ? 0 : t - k); i <= (t + k > 25 ? 25 : t + k);
           i++) {
        dp[t] = max(dp[t], dp[i]);
      }
      res = max(res, ++dp[t]);
    }
    return res;
  }
};
