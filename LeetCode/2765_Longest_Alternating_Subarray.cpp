class Solution {
public:
  int alternatingSubarray(vector<int> &nums) {
    int result = 0;
    vector<int> dp(nums.size(), 0);
    for (int i = 0; i < nums.size() - 1; i++) {
      if (1 == nums[i + 1] - nums[i]) {
        if (0 == dp[i] % 2)
          dp[i + 1] = dp[i] + 1;
        else
          dp[i + 1] = 1;
      } else if (-1 == nums[i + 1] - nums[i]) {
        if (1 == dp[i] % 2)
          dp[i + 1] = dp[i] + 1;
      }
      if (dp[i + 1] > result)
        result = dp[i + 1];
    }
    if (result == 0)
      return -1;
    return result + 1;
  }
};
