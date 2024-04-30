class Solution {
public:
  const int MOD = 1e9 + 7;

  int countRoutes(vector<int> &locations, int start, int finish, int fuel) {
    int n = locations.size();
    vector<vector<int>> dp(201, vector<int>(101, 0));
    dp[fuel][start] = 1;
    for (int i = fuel; i >= 0; i--) {
      for (int j = 0; j < n; j++) {
        if (0 == dp[i][j]) {
          continue;
        }
        for (int k = 0; k < n; k++) {
          if (j == k || 0 > i - abs(locations[j] - locations[k])) {
            continue;
          }
          dp[i - abs(locations[j] - locations[k])][k] =
              (dp[i - abs(locations[j] - locations[k])][k] + dp[i][j]) % MOD;
        }
      }
    }
    long long res = 0;
    for (int i = 0; i <= fuel; i++) {
      res = (res + dp[i][finish]) % MOD;
    }
    return res;
  }
};
