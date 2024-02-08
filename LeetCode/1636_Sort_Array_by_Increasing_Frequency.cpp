class Solution {
public:
  vector<int> frequencySort(vector<int> &nums) {
    map<int, int> um;
    for (auto it : nums)
      um[-it]++;
    map<int, vector<int>> m;
    for (auto it = um.begin(); it != um.end(); it++) {
      m[it->second].push_back(-it->first);
    }
    vector<int> v;
    for (auto it = m.begin(); it != m.end(); it++) {
      int t = it->first;
      vector<int> cur = it->second;
      for (auto c : cur) {
        for (int j = 0; j < t; j++) {
          v.push_back(c);
        }
      }
    }
    return v;
  }
};
