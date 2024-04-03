class Solution {
public:
  int maxCoins(vector<int> &nums) {
    int ans = 0;
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 2; i < n; i++) {
      for (int j = i - 2; j >= 0; j--) {
        int t = nums[i] * nums[j];
        for (int k = j + 1; k < i; k++) {
          dp[j][i] = max(t * nums[k] + dp[j][k] + dp[k][i], dp[j][i]);
        }
      }
    }
    return dp[0][n - 1];
  }
};
