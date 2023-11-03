class Solution {
public:
  int minOperations(vector<int> &nums, int k) {
    int ans = 0;
    int n = nums.size();
    int cnt = 0;
    map<int, int> m;
    for (int i = n - 1; i >= 0; i--) {
      if (m.find(nums[i]) == m.end() && nums[i] <= k)
        cnt++;
      m[nums[i]] = i;
      if (cnt == k)
        return n - i;
    }

    return n;
  }
};
