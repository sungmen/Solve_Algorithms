class Solution {
public:
  int maxDistance(vector<int> &position, int cnt) {
    sort(position.begin(), position.end());
    int l = position[0];
    int n = position.size();
    int r = position[n - 1];
    if (2 == n) {
      return r - l;
    }
    r = r - l;
    l = 1;
    while (l < r - 1) {
      int m = (l + r) / 2;
      int tCnt = 1;
      int tL = position[0];
      bool bChk = false;
      for (int i = 1; i < n; i++) {
        if (position[i] - tL < m) {
          continue;
        }
        tCnt += 1;
        tL = position[i];
      }
      bChk = (tCnt >= cnt);
      if (false == bChk) {
        r = m - 1;
      } else {
        l = m;
      }
    }
    int tCnt = 1;
    int tL = position[0];
    for (int i = 1; i < n; i++) {
      if (position[i] - tL < r) {
        continue;
      }
      tCnt += 1;
      tL = position[i];
    }
    if (tCnt >= cnt)
      return r;
    return l;
  }
};
