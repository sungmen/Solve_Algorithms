class Solution 
{
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        stack<int> stk;
        int m = prices.size();
        vector<int> ans;
        ans = prices;
        for (int i = 0; i < m; i++)
        {
            while (!stk.empty() && prices[stk.top()] >= prices[i])
            {
                ans[stk.top()] = prices[stk.top()] - prices[i];
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};