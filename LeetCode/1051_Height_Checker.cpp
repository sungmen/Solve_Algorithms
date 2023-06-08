class Solution 
{
public:
    int heightChecker(vector<int>& heights) 
    {
        vector<int> comp(heights);
        sort(comp.begin(), comp.end());
        int ans = 0;
        for (int i = 0; i < comp.size(); i++)
        {
            if (heights[i] != comp[i]) ans++;
        }
        return ans;
    }
};