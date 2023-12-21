class Solution {
public:
  int maxWidthOfVerticalArea(vector<vector<int>> &points) {
    map<int, int> m;
    for (auto p : points)
      m[p[0]] = 1;
    auto it = m.begin();
    auto it2 = it;
    it2++;
    int ans = 0;
    for (; it2 != m.end(); it2++) {
      ans = max(ans, it2->first - it->first);
      it = it2;
    }
    return ans;
  }
};
