class Solution {
public:
  long long wonderfulSubstrings(string word) {
    int sum = 0;
    long long ans = 0;
    unordered_map<int, int> um;
    for (int i = 0; i < word.size(); i++) {
      sum ^= (1 << (word[i] - 'a'));
      if (0 == (sum & (sum - 1))) {
        ans++;
      }
      for (auto j = um.begin(); j != um.end(); j++) {
        int c = sum ^ j->first;
        if (0 == (c & (c - 1))) {
          ans += j->second;
        }
      }
      um[sum]++;
    }
    return ans;
  }
};
