class Solution 
{
public:
    vector<int> targetIndices(vector<int>& nums, int target) 
    {
        int a = 0, r = 0;
        for (auto num : nums)
        {
            if (target == num)a++;
            else if (target > num)r++;
        }
        vector<int> ans;
        while(a--)
        {
            ans.push_back(r++);
        }

        return ans;    
    }
};