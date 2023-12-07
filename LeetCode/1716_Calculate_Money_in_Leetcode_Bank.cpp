class Solution {
public:
  int totalMoney(int n) {
    int t = n / 7;
    int d = n % 7;
    int ans = ((28 * t) + (7 * (t * (t - 1) / 2)));
    for (int i = 1; i <= d; i++)
      ans += (t + i);
    return ans;
  }
};
