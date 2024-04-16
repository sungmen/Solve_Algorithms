class Solution {
public:
  struct th {
    priority_queue<long long> p, pMin;
    int len = 0;
  };

  th dfs(int idx, unordered_map<int, vector<int>> &um, vector<int> &cost,
         vector<long long> &ans, vector<bool> &chk) {
    priority_queue<long long> pq;
    priority_queue<long long> pqMin;
    chk[idx] = 1;
    int len = 1;
    pq.push(-cost[idx]);
    pqMin.push(cost[idx]);

    for (auto i : um[idx]) {
      if (1 == chk[i]) {
        continue;
      }
      th cur = dfs(i, um, cost, ans, chk);
      while (!cur.p.empty()) {
        pq.push(cur.p.top());
        cur.p.pop();
      }
      while (pq.size() > 3) {
        pq.pop();
      }
      while (!cur.pMin.empty()) {
        pqMin.push(cur.pMin.top());
        cur.pMin.pop();
      }
      while (pqMin.size() > 2) {
        pqMin.pop();
      }
      len += cur.len;
    }
    if (pq.size() < 3) {
      ans[idx] = 1;
      return {pq, pqMin, len};
    }
    vector<int> v;
    long long res = 1;
    long long res2 = 1;
    for (int j = 0; j < 3; j++) {
      res *= (long long)(-pq.top());
      if (2 == j) {
        res2 *= (long long)(-pq.top());
      }
      v.push_back(pq.top());
      pq.pop();
    }
    if (len > 3) {
      vector<int> v2;
      for (int l = 0; l < 2; l++) {
        res2 *= (long long)(pqMin.top());
        v2.push_back(pqMin.top());
        pqMin.pop();
      }
      res = max(res, res2);
      for (auto m : v2) {
        pqMin.push(m);
      }
    }
    ans[idx] = (res <= 0 ? 0 : res);
    for (auto k : v) {
      pq.push(k);
    }
    return {pq, pqMin, len};
  }

  vector<long long> placedCoins(vector<vector<int>> &edges, vector<int> &cost) {
    vector<long long> ans(cost.size());
    vector<bool> chk(cost.size(), 0);
    unordered_map<int, vector<int>> um;
    for (auto edge : edges) {
      um[edge[0]].push_back(edge[1]);
      um[edge[1]].push_back(edge[0]);
    }
    dfs(0, um, cost, ans, chk);
    return ans;
  }
};
