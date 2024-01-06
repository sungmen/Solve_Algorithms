class Solution {
public:
  int findValueOfPartition(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int ans = 1e9;
    for (int i = 0; i < nums.size() - 1; i++) {
      ans = min(ans, nums[i + 1] - nums[i]);
    }
    return ans;
  }
};
