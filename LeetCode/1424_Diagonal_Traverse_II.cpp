class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &nums) {
    vector<vector<int>> v;
    for (int i = 0; i < nums.size(); i++) {
      int n = nums[i].size();
      for (int j = 0; j < n; j++) {
        int t = i + j;
        if (v.size() == t) {
          vector<int> c;
          c.push_back(nums[i][j]);
          v.push_back(c);
        } else {
          v[t].insert(v[t].begin(), nums[i][j]);
        }
      }
    }
    vector<int> ans;
    for (auto j : v) {
      for (auto i : j) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};
