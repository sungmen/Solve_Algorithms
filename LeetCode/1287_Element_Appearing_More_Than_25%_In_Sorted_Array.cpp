class Solution {
public:
  int findSpecialInteger(vector<int> &arr) {
    int ans = arr[0];
    int maxCnt = 1;
    int cnt = 1;
    int backCnt = 0;
    int back = arr[0];
    for (int idx = 1; idx < arr.size(); idx++) {
      if (arr[idx] == back) {
        cnt++;
      } else {
        if (backCnt < cnt) {
          ans = back;
          backCnt = cnt;
        }
        back = arr[idx];
        cnt = 1;
      }
    }
    if (backCnt < cnt) {
      ans = arr[arr.size() - 1];
    }
    return ans;
  }
};
