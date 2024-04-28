class Solution {
public:
  struct th {
    long long val, cnt, index;
  };
  long long maximumSumOfHeights(vector<int> &heights) {
    long long ans = 0;
    int n = heights.size();
    vector<long long> dpDown(n, 0), dpUp(n, 0);
    stack<th> stk;
    stk.push({heights[0], 1, 0});
    dpUp[0] = heights[0];
    for (int i = 1; i < n; i++) {
      int cnt = 1;
      long long val = heights[i];
      long long ans = val;
      while (!stk.empty() && stk.top().val > val) {
        th cur = stk.top();
        stk.pop();
        cnt += cur.cnt;
        ans += cur.cnt * val;
      }
      if (!stk.empty()) {
        ans += dpUp[stk.top().index];
      }
      stk.push({val, cnt, i});
      dpUp[i] = ans;
    }
    dpDown[n - 1] = heights[n - 1];
    while (!stk.empty()) {
      stk.pop();
    }
    stk.push({heights[n - 1], 1, n - 1});
    dpDown[n - 1] = heights[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      int cnt = 1;
      long long val = heights[i];
      long long ans = val;
      while (!stk.empty() && stk.top().val > val) {
        th cur = stk.top();
        stk.pop();
        cnt += cur.cnt;
        ans += cur.cnt * val;
      }
      if (!stk.empty()) {
        ans += dpDown[stk.top().index];
      }
      stk.push({val, cnt, i});
      dpDown[i] = ans;
    }
    for (int i = 0; i < n; i++) {
      ans = max(ans, dpUp[i] + dpDown[i] - heights[i]);
    }

    return ans;
  }
};
