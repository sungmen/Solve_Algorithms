class Solution {
public:
  int maxScore(string s) {
    int n = s.size() - 1;
    vector<int> v(n, 0), v2(n, 0);
    if (s[0] == '0')
      v[0]++;
    for (int idx = 1; idx < n; idx++) {
      v[idx] = v[idx - 1];
      if (s[idx] == '0')
        v[idx]++;
    }
    if (s[n] == '1')
      v2[n - 1]++;
    v[n - 1] += v2[n - 1];
    for (int idx = n - 2; idx >= 0; idx--) {
      v2[idx] = v2[idx + 1];
      if (s[idx + 1] == '1')
        v2[idx]++;
      v[idx] += v2[idx];
    }
    return *(max_element(v.begin(), v.end()));
  }
};
