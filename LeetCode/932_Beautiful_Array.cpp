class Solution {
public:
  vector<int> beautifulArray(int n) {
    vector<int> ans;
    ans.emplace_back(1);
    while (n > ans.size()) {
      vector<int> tmp;
      for (auto it : ans) {
        if (it * 2 > n) {
          continue;
        }
        tmp.emplace_back(it * 2);
      }
      for (auto it : ans) {
        if (it * 2 - 1 > n) {
          continue;
        }
        tmp.emplace_back(it * 2 - 1);
      }
      ans = tmp;
    }
    return ans;
  }
};
