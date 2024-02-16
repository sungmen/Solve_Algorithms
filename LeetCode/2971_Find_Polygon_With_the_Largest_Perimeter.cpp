class Solution {
public:
  long long largestPerimeter(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    long long sum = 0;
    sum = std::accumulate(nums.begin(), nums.end(), 0L);
    while (nums.size() > 2) {
      sum -= nums.back();
      if (sum > nums.back()) {
        return sum + nums.back();
      }
      nums.pop_back();
    }
    return -1;
  }
};
