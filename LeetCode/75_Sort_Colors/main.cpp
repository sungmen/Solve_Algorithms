class Solution {
public:    
    vector<int> sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid = 0;
        while (mid <= r) {
            switch (nums[mid]) {
                case 0:
                    swap(nums[l++], nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid], nums[r--]);
                    break;
            }
        }
        return nums;
    }
};