class Solution {
public:
  int minimumMountainRemovals(vector<int> &nums) {
    int n = nums.size();
    vector<int> upper(n, 1);
    vector<int> downv(n, 1);
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          upper[i] = max(upper[j] + 1, upper[i]);
        }
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j > i; j--) {
        if (nums[i] > nums[j]) {
          downv[i] = max(downv[j] + 1, downv[i]);
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (1 == upper[i] || 1 == downv[i]) {
        continue;
      }
      ans = max(ans, upper[i] + downv[i] - 1);
    }
    return n - ans;
  }
};
