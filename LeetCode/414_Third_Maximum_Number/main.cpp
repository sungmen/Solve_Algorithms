class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        nums.assign(s.begin(), s.end());
        sort(nums.begin(), nums.end(), greater<int>());
        if(nums.size() < 3) {
            return nums[0];
        } else {
            return nums[2];
        }
    }
};