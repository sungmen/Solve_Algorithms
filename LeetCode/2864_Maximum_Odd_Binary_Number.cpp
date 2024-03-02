class Solution {
public:
  string maximumOddBinaryNumber(string s) {
    int zero = count(s.begin(), s.end(), '0');
    int one = s.size() - zero;
    string f(one - 1, '1');
    string z(zero, '0');
    return f + z + "1";
  }
};
