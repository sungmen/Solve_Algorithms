class Solution {
public:
  vector<int> numberGame(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int idx = 0; idx < nums.size(); idx += 2) {
      swap(nums[idx], nums[idx + 1]);
    }
    return nums;
  }
};
