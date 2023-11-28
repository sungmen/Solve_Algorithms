class Solution {
public:
  int knightDialer(int n) {
    int mod = 1e9 + 7;
    int ans = 0;
    vector<long long> v(11, 1);
    vector<long long> tmp(11, 0);
    for (int i = 1; i < n; i++) {
      tmp[0] = (v[6] + v[4]) % mod;
      tmp[1] = (v[6] + v[8]) % mod;
      tmp[2] = (v[7] + v[9]) % mod;
      tmp[3] = (v[4] + v[8]) % mod;
      tmp[4] = (v[3] + v[9] + v[0]) % mod;
      tmp[5] = (0) % mod;
      tmp[6] = (v[1] + v[7] + v[0]) % mod;
      tmp[7] = (v[2] + v[6]) % mod;
      tmp[8] = (v[1] + v[3]) % mod;
      tmp[9] = (v[2] + v[4]) % mod;
      v = tmp;
    }
    tmp.clear();
    for (int i = 0; i < 10; i++) {
      ans = (ans + v[i]) % mod;
    }

    return ans;
  }
};
