class Solution {
public:
  int maxNumOfMarkedIndices(vector<int> &nums) {
    if (1 == nums.size()) {
      return 0;
    }

    sort(nums.begin(), nums.end());
    int l = 0, r = nums.size() / 2;
    unordered_map<int, int> um;
    while (l < nums.size() && r < nums.size()) {
      if (nums[l] * 2 <= nums[r] && um.find(l) == um.end() &&
          um.find(r) == um.end()) {
        um[l] = 1;
        um[r] = 1;
        l++;
        r++;
      } else {
        if (r < nums.size() - 1) {
          r++;
        } else {
          l++;
        }
      }
    }
    return um.size();
  }
};
