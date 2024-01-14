class Solution {
public:
  int removeAlmostEqualCharacters(string word) {
    int idx = 0;
    int ans = 0;
    while (idx < word.size() - 1) {
      if (word[idx] == word[idx + 1] || 1 == abs(word[idx] - word[idx + 1])) {
        idx++;
        ++ans;
      }
      idx++;
    }
    return ans;
  }
};
