class Solution {
public:
  unordered_map<int, vector<int>> um;
  Solution(vector<int> &nums) {
    for (int idx = 0; idx < nums.size(); idx++) {
      um[nums[idx]].push_back(idx);
    }
  }

  int pick(int target) {
    int si = um[target].size();
    return um[target][rand() % si];
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
