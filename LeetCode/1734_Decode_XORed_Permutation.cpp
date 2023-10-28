class Solution {
public:
  vector<int> decode(vector<int> &encoded) {
    int a = 0;
    int n = encoded.size();
    int b = 0;
    int p = 0;
    int x = 0;
    vector<int> res;
    for (int i = 1; i <= n + 1; i++)
      a ^= i;
    for (auto i : encoded) {
      p ^= i;
      b ^= p;
    }
    x = a ^ b;
    res.push_back(x);
    for (auto i : encoded) {
      x ^= i;
      res.push_back(x);
    }
    return res;
  }
};
