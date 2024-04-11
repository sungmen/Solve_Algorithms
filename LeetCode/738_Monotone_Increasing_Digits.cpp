class Solution {
public:
  int monotoneIncreasingDigits(int n) {
    string ans = to_string(n);
    int c = 1;
    while (c < ans.size() && ans[c] >= ans[c - 1]) {
      c++;
    }
    while (c > 0 && ans[c - 1] > ans[c] && c < ans.size()) {
      ans[c - 1]--;
      c--;
    }
    for (int i = c + 1; i < ans.size(); i++) {
      ans[i] = '9';
    }
    return stoi(ans);
  }
};
