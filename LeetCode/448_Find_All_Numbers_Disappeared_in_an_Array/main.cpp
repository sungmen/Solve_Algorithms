class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> tmp(nums.size() + 1, false);
        for (auto n : nums) {
            tmp[n] = 1;
        }
        vector<int> answer;
        for (int i = 1; i <= nums.size(); ++i) {
            if (!tmp[i]) {
                answer.push_back(i);
            }
        }
        return answer;
    }
};