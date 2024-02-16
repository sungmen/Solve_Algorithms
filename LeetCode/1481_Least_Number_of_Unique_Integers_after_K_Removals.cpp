class Solution {
public:
  int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
    if (k == arr.size())
      return 0;
    unordered_map<int, int> um;
    set<int> s;
    for (auto it : arr) {
      um[it]++;
      if (1 == um[it])
        s.insert(it);
      else if (s.find(it) != s.end()) {
        s.erase(it);
      }
    }
    int num = min(k, (int)s.size());
    if (num == k)
      return um.size() - k;
    int cnt = um.size() - num;
    num = k - num;
    map<int, vector<int>> m;
    for (auto &it : um) {
      if (1 == it.second)
        continue;
      m[it.second].push_back(it.first);
    }
    for (auto &it : m) {
      int f = it.first;
      int t = it.second.size();
      while (t--) {
        num -= f;
        if (num >= 0)
          cnt--;
        else {
          return cnt;
        }
      }
    }

    return cnt;
  }
};
