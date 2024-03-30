class Solution {
public:
  long long countSubarrays(vector<int> &nums, int k) {
    int n = nums.size();
    long long maxNum = *max_element(nums.begin(), nums.end());
    int kCount = 0;
    long long ans = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
      if (nums[r] == maxNum) {
        kCount++;
      }
      while (k <= kCount) {
        if (maxNum == nums[l++]) {
          kCount--;
        }
        ans += n - r;
      }
    }
    return ans;
  }
};
