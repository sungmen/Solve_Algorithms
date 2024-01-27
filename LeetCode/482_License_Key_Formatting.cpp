class Solution {
public:
  string licenseKeyFormatting(string s, int k) {
    string result = "";
    int cnt = 0;
    int n = s.size() - 1;
    for (int idx = n; idx >= 0; idx--) {
      if (s[idx] == '-')
        continue;
      if (cnt == k) {
        result += '-';
        cnt = 0;
      }
      if (s[idx] >= 'a' && s[idx] <= 'z')
        result += (s[idx] - 32);
      else
        result += s[idx];
      cnt++;
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
