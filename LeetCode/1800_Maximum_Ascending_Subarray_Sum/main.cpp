class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int tmp = nums[0], tmpSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (tmp < nums[i]) {
                tmpSum += nums[i];
            } else {
                tmpSum = nums[i];
            }
            tmp = nums[i];
            if (sum < tmpSum) sum = tmpSum;
        }
        return sum;
    }
};