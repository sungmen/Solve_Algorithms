class Solution {
public:
  int sumCounts(vector<int> &nums) {
    int n = nums.size();
    int ans = n;
    for (int i = 0; i < n; i++) {
      unordered_map<int, int> um;
      um[nums[i]] = 1;
      for (int j = i + 1; j < n; j++) {
        um[nums[j]] = 1;
        ans += (um.size() * um.size());
      }
    }
    return ans;
  }
};
