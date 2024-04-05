class Solution {
public:
  string smallestString(string s) {
    int l = 0;
    int n = s.size();
    int cnt = 0;
    while (l < n && 'a' == s[l]) {
      l++;
    }
    if (l == n) {
      s[--l] += 25;
      return s;
    }
    for (; l < n; l++) {
      if ('a' == s[l]) {
        break;
      }
      s[l]--;
    }
    return s;
  }
};
