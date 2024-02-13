class Solution {
public:
  int minimumIndex(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> um;
    for (auto it : nums) {
      um[it]++;
    }

    int divNum = -1;
    for (auto it : um) {
      if (n >= it.second * 2) {
        continue;
      }
      divNum = it.first;
      break;
    }

    int cnt = 0;
    int cnt2 = um[divNum] - cnt;
    for (int idx = 0; idx < n; idx++) {
      if (divNum == nums[idx]) {
        cnt++;
        cnt2--;
      }
      if (idx + 1 >= cnt * 2 || n - idx - 1 >= cnt2 * 2) {
        continue;
      }
      return idx;
    }

    return -1;
  }
};
