class Solution {
public:
  int minimumOneBitOperations(int n) {
    int ans = 0;
    int b = 1;
    for (int i = 30; i >= 0; i--) {
      long long t = (long long)(1 << i);
      if ((n & t) == 0)
        continue;
      ans += (b ? (1 << (i + 1)) - 1 : -((1 << (i + 1)) - 1));
      b ^= 1;
    }
    return ans;
  }
};
