class Solution 
{
public:
    int minDeletion(vector<int>& nums) 
    {
        stack<int> stk;
        for (auto num : nums)
        {
            if (stk.size() % 2 && stk.top() == num)
            {
                continue;
            }
            stk.push(num);
        }
        return nums.size() - stk.size() + (stk.size() % 2);
    }
};