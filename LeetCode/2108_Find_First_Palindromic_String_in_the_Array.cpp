class Solution {
public:
  string firstPalindrome(vector<string> &words) {
    for (auto &str : words) {
      string rev = str;
      reverse(rev.begin(), rev.end());
      if (str != rev)
        continue;

      return str;
    }
    return "";
  }
};
