class Solution {
public:
  int buyChoco(vector<int> &prices, int money) {
    int ans = 0;
    int a = INT_MAX, b = INT_MAX;
    for (int it : prices) {
      if (a > it) {
        b = a;
        a = it;
      } else if (b > it) {
        b = it;
      }
    }
    ans = a + b;
    return (ans <= money ? money - ans : money);
  }
};
