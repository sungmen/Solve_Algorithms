class Solution {
public:
  int maxLengthBetweenEqualCharacters(string s) {
    int res = -1;
    unordered_map<char, int> um;
    for (int i = 0; i < s.size(); i++) {
      if (um.find(s[i]) == um.end()) {
        um[s[i]] = i;
      } else {
        res = max(res, i - um[s[i]] - 1);
      }
    }
    return res;
  }
};
