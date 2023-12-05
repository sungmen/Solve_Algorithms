class Solution {
public:
  string largestGoodInteger(string num) {
    int cnt = 1;
    char d = '/';
    for (int idx = 0; idx < num.size() - 1; idx++) {
      if (num[idx] == num[idx + 1]) {
        cnt++;
      } else {
        cnt = 1;
      }
      if (cnt == 3 && d < num[idx]) {
        d = num[idx];
      }
    }
    return (d == '/' ? "" : string(3, d));
  }
};
