class Solution {
public:
  int minimumSwap(string s1, string s2) {
    int n = s1.size();
    int a = 0, b = 0;
    int answer = 0;
    for (int i = 0; i < n; i++) {
      if (s1[i] == s2[i])
        continue;

      if (s1[i] == 'x')
        ++a;
      else
        ++b;
    }
    if (0 != (a + b) % 2)
      return -1;
    return a / 2 + a % 2 + b / 2 + b % 2;
  }
};
