class Solution {
public:
  int maxProductDifference(vector<int> &nums) {
    int n1 = INT_MAX, n2 = INT_MAX, n3 = INT_MIN, n4 = INT_MIN;
    for (auto it : nums) {
      if (it >= n3) {
        n4 = n3;
        n3 = it;
      } else if (it >= n4) {
        n4 = it;
      }
      if (it <= n1) {
        n2 = n1;
        n1 = it;
      } else if (it <= n2) {
        n2 = it;
      }
    }
    return n3 * n4 - n2 * n1;
  }
};
