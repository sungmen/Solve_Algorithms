class Solution {
public:
  int longestMountain(vector<int> &arr) {
    int n = arr.size();
    vector<int> dpup(n, 0);
    vector<int> dpd(n, 0);
    for (int i = 1; i < n; i++) {
      dpup[i] = (arr[i] > arr[i - 1] ? dpup[i - 1] + 1 : 0);
    }
    for (int i = n - 2; i >= 0; i--) {
      dpd[i] = (arr[i] > arr[i + 1] ? dpd[i + 1] + 1 : 0);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (dpup[i] == 0 || dpd[i] == 0)
        continue;
      ans = max(ans, dpup[i] + dpd[i] + 1);
    }
    return ans;
  }
};
