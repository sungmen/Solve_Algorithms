class Solution 
{
public:
    vector<int> countBits(int n) 
    {
        vector<int> ans;
        int p = 0, c = 0;
        ans.emplace_back(0);
        for (int i = 1; i <= n; i++)
        {
            if ((1<<p)==i)
            {
                p++;
                c = 1;
                ans.emplace_back(1);
            }
            else
            {
                ans.emplace_back(ans[c] + 1);
                c++;
            }
        }
        return ans;
    }
};