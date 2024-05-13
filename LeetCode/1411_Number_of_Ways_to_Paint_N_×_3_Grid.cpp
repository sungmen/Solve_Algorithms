class Solution {
public:
  const int MOD = 1e9 + 7;

  int numOfWays(int n) {
    long long backSameColor = 6;
    long long backOtherColor = 6;

    for (int i = 2; i <= n; i++) {
      long long SameColor =
          ((backSameColor * 3) % MOD + (backOtherColor * 2) % MOD) % MOD;
      long long OtherColor =
          ((backSameColor * 2) % MOD + (backOtherColor * 2) % MOD) % MOD;
      backSameColor = SameColor;
      backOtherColor = OtherColor;
    }

    int ans = (backSameColor + backOtherColor) % MOD;

    return ans;
  }
};
