class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            if (target > nums[l]) ++l;
            else if (target < nums[r]) --r;
            else return {l, r};
            
        }
        return {-1, -1};
    }
};