class Solution 
{
public:
    int minDeletionSize(vector<string>& strs) 
    {
        int ans = 0;
        for (int i = 0; i < strs[0].size(); i++)
        {
            string str = "";
            for (int j = 0; j < strs.size(); j++)
            {
                str += strs[j][i];
            }
            if (! is_sorted(str.begin(), str.end()))
            {
                ans++;
            }
        }
        
        return ans;
    }
};