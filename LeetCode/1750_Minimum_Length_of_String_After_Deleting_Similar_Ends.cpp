class Solution {
public:
  int minimumLength(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
      if (s[l] != s[r]) {
        break;
      }
      int tl = l;
      int tr = r;
      int p = s[l];
      while (p == s[l]) {
        l++;
      }
      while (l < r && p == s[r]) {
        r--;
      }
      if (tl == l || tr == r) {
        break;
      }
    }
    return r - l + 1;
  }
};
