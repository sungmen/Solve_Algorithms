class Solution {
public:
  string toHex(int num) {
    long long num_ = num;
    string res = "";
    if (0 == num_)
      res += '0';
    if (0 > num_)
      num_ += ((long long)1 << 32);
    while (0 < num_) {
      int r = num_ % 16;
      num_ /= 16;
      if (10 <= r) {
        r -= 10;
        res += (r + 'a');
      } else {
        res += (r + '0');
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
