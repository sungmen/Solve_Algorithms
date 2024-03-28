class Solution {
public:
  int maxSubarrayLength(vector<int> &nums, int k) {
    unordered_map<int, int> arr;
    int l = -1;
    int n = nums.size();
    int ans = 0;
    for (int r = 0; r < n; r++) {
      if (++arr[nums[r]] <= k) {
        ans = max(ans, r - l);
        continue;
      }
      cout << "t";
      while (l < r) {
        --arr[nums[++l]];
        if (arr[nums[l]] == arr[nums[r]]) {
          break;
        }
      }
    }
    return ans;
  }
};
