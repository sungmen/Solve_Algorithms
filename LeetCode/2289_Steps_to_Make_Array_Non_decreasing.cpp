class Solution 
{
public:
    int totalSteps(vector<int>& nums) 
    {
        int cnt = 0, tmp = 0, i, n = nums.size();
        stack<pair<int, int>> stk;
        for (i = n - 1; i >= 0; i--)
        {
            if (stk.empty())
            {
                stk.push({nums[i], 0});
            }
            else
            {
                tmp = 0;
                while (!stk.empty() && stk.top().first < nums[i])
                {
                    tmp = max(stk.top().second, ++tmp);
                    stk.pop();
                }
                cnt = max(cnt, tmp);
                stk.push({nums[i], tmp});
            }
        }
        
        return cnt;
    }
};