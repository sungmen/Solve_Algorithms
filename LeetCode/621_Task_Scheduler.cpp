class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    unordered_map<char, int> um;
    for (auto it : tasks) {
      um[it]++;
    }
    vector<int> vec;
    for (auto it = um.begin(); it != um.end(); it++) {
      vec.push_back(it->second);
    }
    sort(vec.begin(), vec.end());
    int cpuT = vec.back() - 1;
    int tmpT = cpuT * n;
    for (int i = 0; i < vec.size() - 1; i++) {
      tmpT -= min(vec[i], cpuT);
    }
    if (tmpT < 0) {
      return tasks.size();
    }
    return tasks.size() + tmpT;
  }
};
