class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int cur = 0;
        int i = 0;
        while(i < nums.size())
        {
            while(i < nums.size() && nums[i] == 0)
            {
                i++;
            }
            if (i + 1 < nums.size() && nums[i] == nums[i + 1])
            {
                res[cur] = nums[i] * 2;
                i++;
            }
            else if (i < nums.size())
            {
                res[cur] = nums[i];
            }
            i++;
            cur++;
        }

        return res;
    }
};