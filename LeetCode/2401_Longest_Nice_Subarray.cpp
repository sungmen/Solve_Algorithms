class Solution {
public:
  int ans = 0;
  void find(vector<int> &nums, int idx, long long num, int cur) {
    if (ans < cur) {
      ans = cur;
    }
    if (nums.size() == idx + 1)
      return;
    if ((num & (long long)nums[idx + 1]) == 0) {
      find(nums, idx + 1, (num | (long long)nums[idx + 1]), cur + 1);
    }
  }
  int longestNiceSubarray(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++)
      find(nums, i, nums[i], 1);
    return ans;
  }
};
