class Solution {
public:
  int countLargestGroup(int n) {
    int si = 0;
    unordered_map<int, int> um;
    for (int i = 1; i <= n; i++) {
      string str = to_string(i);
      int num = 0;
      for (int j = 0; j < str.size(); j++) {
        num = num + (str[j] - '0');
      }
      um[num]++;
      si = max(si, um[num]);
    }
    int ans = 0;
    for (auto it = um.begin(); it != um.end(); it++) {
      if (it->second == si)
        ans++;
    }
    return ans;
  }
};
