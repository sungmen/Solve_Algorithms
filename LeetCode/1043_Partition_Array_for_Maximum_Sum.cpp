class Solution {
public:
  int maxSumAfterPartitioning(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
      int m = 0, b = 0;
      for (int j = 1; j <= k; j++) {
        int d = i - j;
        if (d < 0)
          break;
        m = max(m, arr[d]);
        b = max(b, dp[d] + m * j);
      }
      dp[i] = b;
    }
    return dp[n];
  }
};
