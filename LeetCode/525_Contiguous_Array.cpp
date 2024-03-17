class Solution {
public:
  int findMaxLength(vector<int> &nums) {
    int ans = 0;
    int zero = 0;
    int one = 0;
    int n = nums.size();
    map<int, int> m;
    m[0] = -1;
    for (int i = 0; i < n; i++) {
      one += nums[i];
      zero = i - one + 1;
      if (m.find(one - zero) == m.end()) {
        m[one - zero] = i;
      } else {
        ans = max(ans, i - m[one - zero]);
      }
    }
    return ans;
  }
};
