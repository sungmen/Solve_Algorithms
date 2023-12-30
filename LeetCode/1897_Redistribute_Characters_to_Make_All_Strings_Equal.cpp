class Solution {
public:
  bool makeEqual(vector<string> &words) {
    int n = words.size();
    int arr[26];
    memset(arr, 0, sizeof(arr));
    for (auto s : words) {
      for (auto c : s) {
        arr[c - 'a']++;
      }
    }
    for (int i = 0; i < 26; i++) {
      if (arr[i] % n)
        return false;
    }
    return true;
  }
};
