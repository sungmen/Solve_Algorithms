class Solution 
{
public:
    int minFlips(vector<vector<int>>& grid) 
    {
        int colCnt = 0;
        int rowCnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            int j = 0;
            int k = m - 1;
            while (j < k)
            {
                colCnt += (int)(grid[i][j] != grid[i][k]);
                j++;
                k--;
            }
        }

        for (int i = 0; i < m; i++)
        {
            int j = 0;
            int k = n - 1;
            while (j < k)
            {
                rowCnt += (int)(grid[j][i] != grid[k][i]);
                j++;
                k--;
            }
        }

        int result = min(colCnt, rowCnt);
        return result;
    }
};
