class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < nums.size(); j += n) {
                v.emplace_back(nums[j]);
            }
        }
        return v;
    }
};