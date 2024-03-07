class Solution {
public:
  int countBalls(int lowLimit, int highLimit) {
    unordered_map<int, int> um;
    int ans = 0;
    for (int i = lowLimit; i <= highLimit; i++) {
      int cur = 0;
      int p = i;
      while (0 != p) {
        cur += p % 10;
        p /= 10;
      }
      ans = max(++um[cur], ans);
    }
    return ans;
  }
};
