class Solution {
public:
  vector<int> partitionLabels(string s) {
    vector<pair<int, int>> v(26, {-1, -1});
    for (int i = 0; i < s.size(); i++) {
      int n = s[i] - 'a';
      if (v[n].first == -1) {
        v[n].first = i;
        v[n].second = i;
      } else {
        v[n].second = i;
      }
    }
    int f = -1, e = -1;
    vector<int> res;
    for (int i = 0; i < s.size(); i++) {
      if (e == -1) {
        f = i;
        e = v[s[i] - 'a'].second;
        if (f == e) {
          res.push_back(1);
          e = -1;
        }
      } else if (v[s[i] - 'a'].second > e) {
        e = v[s[i] - 'a'].second;
      } else if (e == i) {
        res.push_back(e - f + 1);
        e = -1;
      }
    }
    return res;
  }
};
