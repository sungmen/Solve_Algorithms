class Solution {
public:
  int numSpecial(vector<vector<int>> &mat) {
    unordered_map<int, unordered_map<int, int>> r, c;
    map<pair<int, int>, int> m;
    int answer = 0;
    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < mat[0].size(); j++) {
        if (1 == mat[i][j]) {
          r[i][j] = 1;
          c[j][i] = 1;
          m[{i, j}] = 1;
          answer++;
        }
      }
    }
    for (auto it = m.begin(); it != m.end(); it++) {
      int y = it->first.first;
      int x = it->first.second;
      if (r[y].size() > 1 || c[x].size() > 1) {
        answer--;
      }
    }
    return answer;
  }
};
