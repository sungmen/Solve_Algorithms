class Solution {
public:
  static bool compare(vector<int> a, vector<int> b) {
    int d = abs(a[0] - a[1]);
    int d2 = abs(b[0] - b[1]);
    return d > d2;
  }

  int twoCitySchedCost(vector<vector<int>> &costs) {
    sort(costs.begin(), costs.end(), compare);
    int an = costs.size() / 2;
    int bn = an;
    int res = 0;
    for (auto cost : costs) {
      if (cost[0] < cost[1]) {
        if (0 >= an)
          res += cost[1];
        else
          res += cost[0];
        an--;
      } else {
        if (0 >= bn)
          res += cost[0];
        else
          res += cost[1];
        bn--;
      }
    }
    return res;
  }
};
