class Solution 
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) 
    {
        vector<vector<int>> res;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n - 2; i++)
        {
            vector<int> resTmp;
            for (int j = 0; j < m - 2; j++)
            {
                int maxNum = 0;
                for (int k = i; k < i + 3; k++)
                {
                    for (int l = j; l < j + 3; l++)
                    {
                        maxNum = max(maxNum, grid[k][l]);
                    }
                }
                resTmp.push_back(maxNum);
            }
            res.push_back(resTmp);
        }
        return res;
    }
};