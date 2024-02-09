class Solution {
public:
  int nthUglyNumber(int n) {
    int result = 0;
    int cnt = 0;
    if (n == 1)
      return 1;
    map<long long, int> um;
    um[1] = 1;
    long long it = um.begin()->first;
    for (int i = 1; i <= n; i++) {
      it = um.begin()->first;
      um.erase(it);
      um[it * 2]++;
      um[it * 3]++;
      um[it * 5]++;
    }
    return it;
  }
};
