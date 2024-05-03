class Solution {
public:
  string makeSmallestPalindrome(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
      char ch = min(s[i], s[n - i - 1]);
      s[i] = s[n - i - 1] = ch;
    }
    return s;
  }
};
