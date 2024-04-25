class Solution {
public:
  bool checkZeroOnes(string s) {
    int zero = 0, one = 0;
    int tZero = 0, tOne = 0;
    for (int i = 0; i < s.size(); i++) {
      if ('0' == s[i]) {
        tOne = 0;
        tZero++;
      } else {
        tZero = 0;
        tOne++;
      }
      one = max(tOne, one);
      zero = max(tZero, zero);
    }
    return one > zero;
  }
};
