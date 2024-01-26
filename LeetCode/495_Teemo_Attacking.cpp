class Solution {
public:
  int findPoisonedDuration(vector<int> &timeSeries, int duration) {
    int n = timeSeries.size() - 1;
    int back = timeSeries[n];
    int ans = duration;
    for (int idx = n - 1; idx >= 0; idx--) {
      ans += min(back - timeSeries[idx], duration);
      back = timeSeries[idx];
    }
    return ans;
  }
};
