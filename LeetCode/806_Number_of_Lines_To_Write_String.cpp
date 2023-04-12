class Solution 
{
public:
    vector<int> numberOfLines(vector<int>& widths, string s) 
    {
        vector<int> ans(2, 0);
        ans[0]++;
        for (auto c : s)
        {
            int tmp = widths[c-'a'];
            if (tmp + ans[1] > 100)
            {
                ans[0]++;
                ans[1] = tmp;
            }
            else
                ans[1] += tmp;
        }
        return ans;
    }
};