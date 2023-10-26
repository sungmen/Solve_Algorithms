class Solution {
public:
  int kthGrammar(int n, int k) {
    k--;
    int c = 0;
    while (1 < n--) {
      if (k < 1 << n)
        continue;
      k -= 1 << n;
      c++;
    }
    return ((c + k) % 2);
  }
};
