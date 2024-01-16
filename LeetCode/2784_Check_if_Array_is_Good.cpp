class Solution {
public:
  bool isGood(vector<int> &nums) {
    if (nums.size() == 1)
      return false;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int idx = 1;
    for (int i = 0; i < n - 2; i++) {
      if (idx == i + 1) {
        idx++;
      } else
        return false;
      if (nums[i] == nums[i + 1])
        return false;
    }
    if (nums[n - 2] == nums[n - 1] && idx == nums[n - 1])
      return true;
    return false;
  }
};
