class Solution {
public:
  int shortestSequence(vector<int> &rolls, int k) {
    int arr[k + 1];
    int t = 0;
    int ans = 1;
    memset(arr, 0, sizeof(arr));
    for (auto roll : rolls) {
      if (1 == arr[roll]) {
        continue;
      }
      arr[roll] = 1;
      if (++t != k) {
        continue;
      }
      ans++;
      t = 0;
      memset(arr, 0, sizeof(arr));
    }
    return ans;
  }
};
