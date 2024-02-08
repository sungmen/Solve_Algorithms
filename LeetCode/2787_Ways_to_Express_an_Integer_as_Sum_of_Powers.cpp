class Solution {
public:
  const int MOD = 1e9 + 7;
  int numberOfWays(int n, int x) {
    vector<vector<long long>> v(n + 2, vector<long long>(n + 2, 0));
    for (int i = 0; i <= n + 1; i++)
      v[0][i] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = n; j >= 1; j--) {
        long long cur = (long long)pow(j, (double)x);
        if (i >= cur)
          v[i][j] = (v[i][j] + v[i - cur][j + 1]) % MOD;
        v[i][j] = (v[i][j] + v[i][j + 1]) % MOD;
      }
    }
    return v[n][1];
  }
};
