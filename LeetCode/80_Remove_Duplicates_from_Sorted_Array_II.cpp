class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int b = nums[0];
        int res = 1;
        int cnt = 1;
        vector<int> v;
        v.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (b == nums[i]) {
                cnt++;
            } else {
                b = nums[i];
                cnt = 1;
            }
            if (cnt > 2) continue;
            v.push_back(nums[i]);
            ++res;
        }
        for (int i = 0; i < v.size(); i++) {
            nums[i] = v[i];
        }
        return res;
    }
};