class Solution {
public:
  bool hasAlternatingBits(int n) {
    bool chk = n % 2;
    while (n) {
      if (chk != n % 2)
        return false;
      n /= 2;
      chk ^= 1;
    }
    return true;
  }
};
