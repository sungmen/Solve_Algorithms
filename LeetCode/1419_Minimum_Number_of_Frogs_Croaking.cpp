class Solution {
public:
  int minNumberOfFrogs(string croakOfFrogs) {
    int ans = 0;
    vector<int> v(5, 0);
    int tmp = 0;
    for (auto chr : croakOfFrogs) {
      ans = max(ans, tmp);
      switch (chr) {
      case 'c':
        v[0]++;
        tmp++;
        break;
      case 'r':
        v[1]++;
        if (v[0] < v[1])
          return -1;
        break;
      case 'o':
        v[2]++;
        if (v[1] < v[2])
          return -1;
        break;
      case 'a':
        v[3]++;
        if (v[2] < v[3])
          return -1;
        break;
      case 'k':
        v[4]++;
        if (v[3] < v[4])
          return -1;
        tmp--;
        break;
      }
    }
    if (v[0] > v[4])
      return -1;
    return ans;
  }
};
