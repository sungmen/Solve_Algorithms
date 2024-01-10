class Solution {
public:
  int minOperations(vector<int> &nums) {
    unordered_map<int, int> um;
    for (auto n : nums) {
      um[n]++;
    }
    int ans = 0;
    for (auto it = um.begin(); it != um.end(); it++) {
      int p = it->second;
      while (p) {
        if (p == 1)
          return -1;
        if (p > 4 || p == 3)
          p -= 3;
        else
          p -= 2;
        ans++;
      }
    }
    return ans;
  }
};
