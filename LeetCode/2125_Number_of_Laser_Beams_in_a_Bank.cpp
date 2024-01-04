class Solution {
public:
  int numberOfBeams(vector<string> &bank) {
    int back = 0;
    int ans = 0;
    for (auto s : bank) {
      int cnt = 0;
      for (auto c : s) {
        if ('1' == c)
          cnt++;
      }
      if (cnt == 0)
        continue;
      if (back == 0) {
        back = cnt;
        continue;
      }
      ans += back * cnt;
      back = cnt;
    }
    return ans;
  }
};
