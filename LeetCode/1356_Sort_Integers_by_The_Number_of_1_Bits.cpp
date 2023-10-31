class Solution {
public:
  vector<int> sortByBits(vector<int> &arr) {
    vector<pair<int, int>> v;
    vector<int> ans;
    for (auto i : arr) {
      v.push_back({__builtin_popcount(i), i});
    }
    sort(v.begin(), v.end());
    for (auto t : v) {
      ans.push_back(t.second);
    }
    return ans;
  }
};
