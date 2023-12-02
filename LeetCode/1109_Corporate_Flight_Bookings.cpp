class Solution {
public:
  vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
    vector<int> dp(n + 1, 0);
    for (auto booking : bookings) {
      dp[booking[0] - 1] += booking[2];
      dp[booking[1]] -= booking[2];
    }
    for (int i = 1; i < n; i++) {
      dp[i] += dp[i - 1];
    }
    return vector<int>(dp.begin(), dp.begin() + n);
  }
};
