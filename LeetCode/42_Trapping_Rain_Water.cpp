class Solution {
public:
  int trap(vector<int> &height) {
    stack<int> left;
    left.push(0);
    int upper = 0;
    int ans = 0;
    map<int, int> endPosition;
    for (int i = 0; i < height.size(); i++) {
      int h = height[i];
      if (upper > h) {
        left.push(h);
        continue;
      }
      while (!left.empty() && left.top() <= h) {
        ans += (upper - left.top());
        left.pop();
      }
      left.push(h);
      endPosition[i] = 1;
      upper = h;
    }
    cout << ans << '\n';
    while (!left.empty()) {
      left.pop();
    }
    left.push(0);
    upper = 0;
    for (int back = height.size() - 1; back >= 0; back--) {
      int h = height[back];
      if (upper > h) {
        left.push(h);
        continue;
      }
      while (!left.empty() && left.top() <= h) {
        ans += (upper - left.top());
        left.pop();
      }
      left.push(h);
      upper = h;
      if (endPosition.find(back) != endPosition.end())
        break;
    }

    return ans;
  }
};
