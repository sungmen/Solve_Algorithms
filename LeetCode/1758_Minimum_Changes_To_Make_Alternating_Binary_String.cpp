class Solution {
public:
  int minOperations(string s) {
    int t1 = 0, t2 = 0;
    int s1 = 0;
    for (auto it : s) {
      if (it - '0' != s1)
        t1++;
      else
        t2++;
      s1 ^= 1;
    }
    return min(t1, t2);
  }
};
