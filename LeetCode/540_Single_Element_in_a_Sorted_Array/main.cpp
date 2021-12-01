class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        int l = 0, r = nums.size() - 1, mid;
        
        while (l < r) {
            mid = (l + r) / 2;
            if (!(mid % 2)) {
                if (nums[mid] == nums[mid + 1]) l = mid + 1;
                else r = mid;
            } else {
                if (nums[mid] == nums[mid - 1]) l = mid + 1;
                else r = mid;
            }
        }
        
        return nums[l];
    }
};