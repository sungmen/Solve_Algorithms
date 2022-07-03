class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int l = 0, m = 0;
        for (auto num : nums)
        {
            if (num < pivot) l++;
            else if (num == pivot) m++;
        }
        int h = l + m, s = 0;
        vector<int> ans(nums.size());
        for (auto num : nums)
        {
            if (num < pivot) ans[s++] = num;
            else if (num == pivot) ans[l++] = num;
            else ans[h++] = num;
        }
        return ans;
    }
};