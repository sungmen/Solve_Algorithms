class Solution {
public:
  int dfs(int n) {
    int res = 0;
    if (n == 1)
      return res;
    if (n % 2) {
      res = dfs(3 * n + 1);
    } else {
      res = dfs(n / 2);
    }
    return res + 1;
  }

  int getKth(int lo, int hi, int k) {
    vector<vector<int>> v;
    for (int it = lo; it <= hi; it++) {
      vector<int> r = {dfs(it), it};
      v.push_back(r);
    }
    sort(v.begin(), v.end());

    auto answer = v[k - 1][1];
    return answer;
  }
};
