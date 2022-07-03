class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), answer = 2e9, sum = 0;
        while (l < n) {
            sum += nums[l++];
            while (sum >= target && r < l) {
                answer = min(answer, l - r);
                sum -= nums[r++];
            }
        }
        return (answer==2e9?0:answer);
    }
};