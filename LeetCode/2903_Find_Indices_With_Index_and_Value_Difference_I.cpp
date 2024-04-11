class Solution {
public:
  vector<int> findIndices(vector<int> &nums, int indexDifference,
                          int valueDifference) {
    vector<int> ans = {-1, -1};
    int n = nums.size();

    for (int i = 0; i < n - indexDifference; i++) {
      for (int j = i + indexDifference; j < n; j++) {
        if (abs(nums[i] - nums[j]) >= valueDifference)
          return {i, j};
      }
    }

    return ans;
  }
};
