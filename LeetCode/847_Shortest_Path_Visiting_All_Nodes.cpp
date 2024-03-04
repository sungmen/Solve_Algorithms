class Solution {
public:
  int shortestPathLength(vector<vector<int>> &graph) {
    int n = graph.size();
    int last = (1 << n) - 1;
    queue<tuple<int, int, int>> q;
    map<pair<int, int>, int> um;
    for (int i = 0; i < n; i++) {

      q.push({i, 0, (1 << i)});
      um[{i, (1 << i)}] = 1;
    }
    int ans = 0;
    while (false == q.empty() && last != get<2>(q.front())) {
      int y = get<0>(q.front());
      int x = get<1>(q.front());
      int z = get<2>(q.front());
      q.pop();
      for (auto it : graph[y]) {
        int next = z | (1 << it);
        if (um.find({it, next}) != um.end())
          continue;

        um[{it, next}] = 1;
        q.push({it, x + 1, next});
      }
    }
    return (true == q.empty() ? -1 : get<1>(q.front()));
  }
};
