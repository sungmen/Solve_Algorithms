class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        pair <int, int> dp[nums.size()];
        for (int i = 0; i < nums.size(); i++) {
            if (!i) dp[0] = {0, sum - nums[i]};
            else dp[i] = {dp[i - 1].first + nums[i - 1], dp[i - 1].second - nums[i]};
            if (dp[i].first == dp[i].second) return i;
        }
        return -1;
    }
};