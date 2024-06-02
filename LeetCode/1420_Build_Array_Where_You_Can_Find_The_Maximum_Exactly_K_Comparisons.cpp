class Solution {
public:
  const int MOD = 1e9 + 7;

  int dp[51][101][51];

  int numOfArrays(int &n, int &m, int &k, int idx = -1, int maximum = -1,
                  int cost = -1) {
    if (-1 == idx && -1 == maximum && -1 == cost) {
      // init()
      memset(dp, -1, sizeof(dp));
      return numOfArrays(n, m, k, 0, 0, 0);
    } else if (n == idx) {
      // n == idx 와 같은 경우는 최대치 이므로 반환
      // k == cost가 같은 경우 search_cost가 같으므로 1
      return (k == cost ? 1 : 0);
    } else if (k < cost) {
      // cost가 k 보다 크면 다음 볼필요 없이 false;
      return 0;
    } else if (-1 != dp[idx][maximum][cost]) {
      return dp[idx][maximum][cost];
    }

    int res = 0;
    for (int i = 1; i <= m; i++) {
      if (maximum < i) {
        res = (res + numOfArrays(n, m, k, idx + 1, i, cost + 1)) % MOD;
      } else {
        res = (res + numOfArrays(n, m, k, idx + 1, maximum, cost)) % MOD;
      }
    }

    dp[idx][maximum][cost] = res;
    return res;
  }
};
