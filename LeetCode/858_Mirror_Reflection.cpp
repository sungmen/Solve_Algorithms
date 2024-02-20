class Solution {
public:
  int mirrorReflection(int p, int q) {
    int t = p * q / __gcd(p, q);
    int a = t / p;
    int b = t / q;
    if (0 == a % 2)
      return 0;
    if (0 == b % 2)
      return 2;
    return 1;
  }
};
