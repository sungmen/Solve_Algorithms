class Solution {
public:
  int integerBreak(int n) {
    if (n == 2)
      return 1;
    if (n == 3)
      return 2;
    int answer = 1;
    while (n > 4) {
      answer *= 3;
      n -= 3;
    }
    answer *= n;

    return answer;
  }
};
