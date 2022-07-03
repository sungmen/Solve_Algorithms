class Solution 
{
public:
    bool find132pattern(vector<int>& nums) 
    {
        stack<int> stk;
        int m = nums.size() - 1, n = INT_MIN;
        for (int i = m; i >= 0; i--) 
        {
            if (n > nums[i])
            {
                return true;
            }
            else if (!stk.empty()) 
            {
                while (!stk.empty() && nums[i] > stk.top())
                {
                    n = stk.top();
                    stk.pop();
                }
            }
            stk.push(nums[i]);
        }
        return false;
    }
};