class Solution {
public:
  int sumIndicesWithKSetBits(vector<int> &nums, int k) {
    int t = nums.size();
    int ans = 0;
    for (int i = 0; i < t; i++) {
      if (__builtin_popcount(i) == k) {
        ans += nums[i];
      }
    }

    return ans;
  }
};
