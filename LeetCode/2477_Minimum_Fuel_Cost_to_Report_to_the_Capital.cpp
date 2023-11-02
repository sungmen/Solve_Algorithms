class Solution {
public:
  int n = 0;
  int seat = 0;
  vector<int> v[100001];
  int chk[100001];
  long long ans[100001];

  int dfs(int idx) {
    chk[idx] = 1;
    long long r = 1;
    for (auto i : v[idx]) {
      if (chk[i])
        continue;
      long long l = dfs(i);
      r += l;
      long long c = l / seat;
      if (0 != l % seat)
        c++;
      ans[idx] += c + ans[i];
    }
    return r;
  }

  long long minimumFuelCost(vector<vector<int>> &roads, int seats) {
    seat = seats;
    n = roads.size();
    for (auto i : roads) {
      v[i[0]].push_back(i[1]);
      v[i[1]].push_back(i[0]);
    }
    dfs(0);
    return ans[0];
  }
};
