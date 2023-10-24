class Solution {
public:
  int smallestDivisor(vector<int> &nums, int threshold) {
    int l = 1;
    int r = 1e6;
    while (l <= r) {
      int m = (l + r) / 2;
      int sum = 0;
      for (auto n : nums) {
        sum += ceil(n / (double)m);
      }
      if (sum <= threshold) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};
