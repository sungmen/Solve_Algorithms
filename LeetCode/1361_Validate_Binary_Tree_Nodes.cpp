class Solution {
public:
  bool validateBinaryTreeNodes(int n, vector<int> &leftChild,
                               vector<int> &rightChild) {
    vector<vector<int>> m(n);
    vector<bool> chk(n, false);
    map<int, int> unStart;
    map<int, int> visit;
    int idx = -1;
    for (auto i : leftChild) {
      idx++;
      if (-1 == i)
        continue;
      m[idx].push_back(i);
      unStart[i]++;
      visit[i]++;
      if (visit[i] > 1)
        return false;
    }
    idx = -1;
    for (auto i : rightChild) {
      idx++;
      if (-1 == i)
        continue;
      m[idx].push_back(i);
      unStart[i]++;
      visit[i]++;
      if (visit[i] > 1)
        return false;
    }
    if (unStart.size() == n || 1 != n - unStart.size())
      return false;
    int start;
    for (int i = 0; i < n; i++) {
      if (unStart.find(i) == unStart.end()) {
        start = i;
        break;
      }
    }
    int cnt = 0;
    queue<int> q;
    q.push(start);
    chk[start] = 1;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      cnt++;
      for (auto it : m[cur]) {
        if (chk[it])
          return false;
        chk[it] = 1;
        q.push(it);
      }
    }
    if (cnt != n)
      return false;
    return true;
  }
};
