class Solution {
public:
  int hIndex(vector<int> &citations) {
    sort(citations.begin(), citations.end());
    int n = citations.size();
    int ans = 0;
    for (int idx = 0; idx < n; idx++) {
      if (citations[idx] < n - idx)
        continue;

      ans = max(ans, n - idx);
    }
    return ans;
  }
};
