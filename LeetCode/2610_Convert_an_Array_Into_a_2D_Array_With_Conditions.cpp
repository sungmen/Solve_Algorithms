class Solution {
public:
  vector<vector<int>> findMatrix(vector<int> &nums) {
    map<int, int> m;
    int row;
    for (int num : nums) {
      m[num]++;
      row = max(row, m[num]);
    }
    vector<vector<int>> answer(row);
    for (auto it = m.begin(); it != m.end(); it++) {
      int num = it->first;
      int cnt = it->second;
      for (int c = 0; c < cnt; c++) {
        answer[c].push_back(num);
      }
    }

    return answer;
  }
};
