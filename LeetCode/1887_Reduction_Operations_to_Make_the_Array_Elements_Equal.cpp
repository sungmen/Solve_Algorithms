class Solution {
public:
  int reductionOperations(vector<int> &nums) {
    int ans = 0;
    int cnt = 0;
    int cur = 0;
    sort(nums.begin(), nums.end());
    cur = nums[0];
    for (auto it : nums) {
      if (cur == it) {
        ans += cnt;
        continue;
      }
      cur = it;
      ans += ++cnt;
    }
    return ans;
  }
};
