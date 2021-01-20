/**
* Runtime: 8 ms, faster than 69.48% of C++ online submissions for Maximum Product Subarray.
* Memory Usage: 11.7 MB, less than 92.33% of C++ online submissions for Maximum Product Subarray.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int dp_max[nums.size()], dp_min[nums.size()];
        dp_min[0] = dp_max[0] = nums[0];
        int MAX = dp_max[0];
        for (int i = 1; i < nums.size(); i++) {
            dp_min[i] = min(dp_min[i-1] * nums[i], min(dp_max[i-1] * nums[i], nums[i]));
            dp_max[i] = max(dp_min[i-1] * nums[i], max(dp_max[i-1] * nums[i], nums[i]));
            MAX = MAX < dp_max[i] ? dp_max[i] : MAX;
        }
        return MAX;
    }
};