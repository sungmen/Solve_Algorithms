class Solution {
public:
  vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k) {
    map<int, vector<int>> um;
    for (auto s : score) {
      um[-s[k]] = s;
    }
    vector<vector<int>> ans;
    for (auto it = um.begin(); it != um.end(); it++) {
      ans.push_back(it->second);
    }
    return ans;
  }
};
