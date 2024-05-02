class Solution {
public:
  int findMaxK(vector<int> &nums) {
    int ans = -1;
    unordered_map<int, int> um;
    for (auto num : nums) {
      um[num] = 1;
      if (um.find(-num) == um.end()) {
        continue;
      }
      if (ans >= abs(num)) {
        continue;
      }
      ans = abs(num);
    }
    return ans;
  }
};
