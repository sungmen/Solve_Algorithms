class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = 1;
        while (r < nums.size() && nums[r - 1] < nums[r]) r++;
        int sl = r, sr = nums.size() - 1;
        --r;
        if (!(target >= nums[l] && target <= nums[r]))
            l = sl, r = sr;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] == target)
            {
                return m;
            }
            else if (nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
};