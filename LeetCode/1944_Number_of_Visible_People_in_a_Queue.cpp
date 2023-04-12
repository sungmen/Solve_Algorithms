class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int>& heights)
    {
        vector<int> ans(heights.size(), 0);
        stack<pair<int, int>> stk;
        for (int idx = heights.size() - 1; idx >= 0; idx--)
        {
            int m = 0;
            int curh = heights[idx];
            if (!stk.empty())
            {
                ans[idx]++;
                while (!stk.empty() && stk.top().first < curh)  
                {
                    stk.pop();
                    if (!stk.empty())
                        ans[idx]++;
                }
            }
            stk.push({curh, idx});
        }

        return ans;
    }
};