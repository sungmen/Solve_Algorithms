class Solution {
public:
  int countTriples(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        double t = sqrt((i * i) + (j * j));
        if (n >= t && (int)t == t) {
          ans += 2;
        }
      }
    }
    return ans;
  }
};
