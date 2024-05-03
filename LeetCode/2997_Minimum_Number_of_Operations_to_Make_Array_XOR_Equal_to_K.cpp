class Solution {
public:
  int minOperations(vector<int> &nums, int k) {
    int nXor = 0;
    for (auto num : nums) {
      nXor ^= num;
    }
    int nWhile = nXor ^ k;
    int res = 0;
    while (nWhile) {
      res += nWhile & 1;
      nWhile = nWhile >> 1;
    }
    return res;
  }
};
