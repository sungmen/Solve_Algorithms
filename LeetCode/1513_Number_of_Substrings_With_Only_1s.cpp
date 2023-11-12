class Solution {
public:
  int numSub(string s) {
    int MOD = 1e9 + 7;
    unsigned long long ans = 0;
    unsigned long long j = 0;
    for (auto i : s) {
      if ('1' == i)
        j++;
      else {
        ans = (ans + ((j + 1) * j / 2)) % MOD;
        j = 0;
      }
    }
    ans = (ans + ((j + 1) * j / 2)) % MOD;
    return (int)ans;
  }
};
