class Solution {
public:
  vector<int> circularPermutation(int n, int start) {
    vector<int> res(1 << n);
    for (int index = 0; index < (1 << n); index++) {
      res[index] = index ^ (index >> 1);
    }
    auto it = find(res.begin(), res.end(), start);
    rotate(res.begin(), it, res.end());

    return res;
  }
};
