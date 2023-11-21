class Solution {
public:
  long long countBadPairs(vector<int> &nums) {
    unordered_map<long long, long long> um;
    long long sum = 0;
    long long n = nums.size();
    for (int i = 0; i < nums.size(); i++) {
      long long add = nums[i] - i;
      sum += um[add];
      um[add]++;
    }
    return (long long)(n * (n - 1) / 2) - sum;
  }
};
