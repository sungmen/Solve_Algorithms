/**
* Runtime: 24 ms, faster than 97.11% of C++ online submissions for Range Sum Query - Immutable.
* Memory Usage: 17.1 MB, less than 96.41% of C++ online submissions for Range Sum Query - Immutable.
*/

class NumArray {
private:
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        if (nums.size() > 1) {
            for (int i = 1; i < nums.size(); i++) {
                this->nums[i] += this->nums[i-1];
            }
        }
    }
    
    int sumRange(int i, int j) {
        if (i) return nums[j] - nums[i - 1];
        else return nums[j];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */