class Solution {
public:    
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        // binary search
        int l = 0, r = nums.size() - 1, m, ans = -1;
        while (l < r) {
            // find mid
            m = (l + r) / 2;
            if (nums[m] < target) l = m + 1;
            else r = m;
        }
        if (nums[l] != target) return {-1, -1};
        ans = l;
        
        // find ans[1]
        r = nums.size() - 1;
        while (l < r) {
            m = ((l + r) / 2) + 1;
            if (nums[m] > target) r = m - 1;
            else l = m;
        }
        return {ans, r};
    }
};