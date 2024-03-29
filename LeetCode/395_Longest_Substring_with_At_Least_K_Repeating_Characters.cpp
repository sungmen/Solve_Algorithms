class Solution {
public:
  int longestSubstring(string s, int k) {
    int arr[26];
    memset(arr, 0, sizeof(arr));
    int n = s.size();
    int countNum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (0 == arr[s[i] - 'a']++) {
        ++countNum;
      }
    }
    for (int i = 1; i <= countNum; i++) {
      memset(arr, 0, sizeof(arr));
      int l = 0;
      int r = 0;
      int cnt = 0;
      int j = 0;
      while (r < n) {
        if (cnt <= i) {
          int idx = s[r] - 'a';
          if (0 == arr[idx]++)
            cnt++;
          if (k == arr[idx])
            j++;
          r++;
        } else {
          int idx = s[l] - 'a';
          if (k == arr[idx]--)
            j--;
          if (0 == arr[idx])
            cnt--;
          l++;
        }
        if (i == cnt && i == j) {
          ans = max(ans, r - l);
        }
      }
    }
    return ans;
  }
};
