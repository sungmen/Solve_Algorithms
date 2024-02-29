#include <iostream>
#include <map>
#include <vector>

using namespace std;

int dfs(map<int, int> &pos, vector<vector<bool>> &chk,
        vector<vector<int>> &land, int y, int x) {
  if (y >= land.size() || y < 0 || x >= land[0].size() || x < 0 ||
      true == chk[y][x] || 0 == land[y][x])
    return 0;
  pos[x] = 1;
  chk[y][x] = true;
  return 1 + dfs(pos, chk, land, y - 1, x) + dfs(pos, chk, land, y + 1, x) +
         dfs(pos, chk, land, y, x - 1) + dfs(pos, chk, land, y, x + 1);
}

int solution(vector<vector<int>> land) {
  int answer = 0;
  int n = land.size();
  int m = land[0].size();
  vector<vector<bool>> chk(n, vector<bool>(m, false));
  map<int, int> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (1 != land[i][j] || false != chk[i][j])
        continue;
      map<int, int> pos;
      int cur = dfs(pos, chk, land, i, j);
      for (auto it = pos.begin(); it != pos.end(); it++) {
        ans[it->first] += cur;
      }
    }
  }
  for (auto it = ans.begin(); it != ans.end(); it++) {
    answer = max(answer, it->second);
  }
  return answer;
}
