class Solution {
public:
  long long countGood(vector<int> &nums, int k) {
    long long ans = 0;
    int n = nums.size();
    unordered_map<int, int> um;
    long long cnt = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
      long long t = ++um[nums[i]];
      if (t > 1) {
        cnt -= ((t - 2) * (t - 1) / 2);
        cnt += ((t - 1) * t / 2);
      }
      if (cnt < k)
        continue;
      while (i >= j && cnt >= k) {
        ans += (n - i);
        long long t = --um[nums[j++]];
        if (0 == t)
          continue;
        cnt -= (t * (t + 1) / 2);
        cnt += (t * (t - 1) / 2);
      }
    }
    return ans;
  }
};
