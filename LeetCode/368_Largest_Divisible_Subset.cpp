class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> dp(n, 0);
    int pos = 0;
    int maxVal = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (0 != nums[i] % nums[j] || dp[i] >= dp[j] + 1) {
          continue;
        }

        dp[i] = dp[j] + 1;

        if (maxVal >= dp[i]) {
          continue;
        }

        pos = i;
        maxVal = dp[i];
      }
    }

    vector<int> result;
    int cur = maxVal;
    for (int i = n - 1; i >= 0; i--) {
      if (0 != nums[pos] % nums[i] || cur != dp[i]) {
        continue;
      }

      result.push_back(nums[i]);
      cur--;
      pos = i;
    }
    return result;
  }
};
