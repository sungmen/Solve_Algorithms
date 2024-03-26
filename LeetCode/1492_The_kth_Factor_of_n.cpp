class Solution {
public:
  int kthFactor(int n, int k) {
    if (1 == n && 1 == k)
      return 1;
    vector<int> v;
    for (int i = 1; i <= sqrt(n); i++) {
      if (0 != n % i) {
        continue;
      }
      int j = n / i;
      v.push_back(i);

      if (i != j)
        v.push_back(j);
    }
    if (k > v.size()) {
      return -1;
    }
    sort(v.begin(), v.end());
    return v[k - 1];
  }
};
