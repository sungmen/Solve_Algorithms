class Solution 
{
public:
    bool checkXMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<bool>> chk(n, vector<bool>(n, false));
        int x = n - 1;
        for (int i = 0; i < n; i++, x--)
        {
            if (grid[i][i] > 0 && grid[i][x] > 0)
            {
                chk[i][i] = 1;
                chk[i][x] = 1;
            }
            else
                return false;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!chk[i][j] && grid[i][j] != 0)
                    return false;
            }
        }
        return true;
    }
};