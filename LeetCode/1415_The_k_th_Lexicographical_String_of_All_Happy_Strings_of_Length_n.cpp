class Solution {
public:
  void dfs(int n, long long num, int backN, vector<long long> &v) {
    if (0 == n) {
      v.push_back(num);
      return;
    }
    num *= 10;
    for (int i = 1; i <= 3; i++) {
      if (backN == i) {
        continue;
      }
      dfs(n - 1, num + i, i, v);
    }
  }

  string getHappyString(int n, int k) {
    vector<long long> v;
    dfs(n, 0, 0, v);
    sort(v.begin(), v.end());
    if (v.size() < k) {
      return "";
    }
    string ans = "";
    long long t = v[k - 1];
    while (t) {
      ans += (char)('a' + ((t % 10) - 1));
      t /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
