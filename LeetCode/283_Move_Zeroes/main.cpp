class Solution {
public:
    vector<int> moveZeroes(vector<int>& nums) {
        int pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                nums[pos++] = nums[i];
            }
        }
        for (int i = pos; i < nums.size(); i++) {
            nums[pos++] = 0;
        }
        return nums;
    }
};