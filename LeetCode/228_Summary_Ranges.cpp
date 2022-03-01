class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (!nums.size()) return {};
        if (nums.size() == 1) return {to_string(nums[0])};
        vector<string> res;
        int idx = 1, l = nums[0], r = nums[0];
        while (idx < nums.size()) {
            while (idx < nums.size() && nums[idx] == r + 1) {
                r = nums[idx];
                idx++;
            }
            if (l == r) res.push_back(to_string(l));
            else res.push_back(to_string(l)+"->"+to_string(r));
            if (idx < nums.size()) {
                l = nums[idx], r = nums[idx];
                idx++;
            }
        }
        if (l == r) res.push_back(to_string(l));
        return res;
    }
};