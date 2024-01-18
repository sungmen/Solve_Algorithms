class Solution {
public:
  vector<int> pathInZigZagTree(int label) {
    int tmp = label;
    int cnt = 0;
    while (tmp) {
      tmp /= 2;
      cnt++;
    }
    vector<int> ans;
    while (cnt) {
      ans.push_back(label);
      if (cnt == 1)
        break;
      if (0 == cnt % 2) {
        label = ((1 << (cnt - 1)) + (1 << cnt) - label - 1) / 2;
      } else {
        label = ((1 << cnt) - (label - (1 << (cnt - 1)) + 1)) / 2;
      }
      cnt--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
