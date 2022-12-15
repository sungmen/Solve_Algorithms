class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> orow(m, 0), ocol(n, 0), zrow(m, 0), zcol(n, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (1 == grid[i][j])
                {
                    orow[i]++;
                    ocol[j]++;
                }
                else
                {
                    zrow[i]++;
                    zcol[j]++;
                }
            }
        }
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res[i][j] = orow[i] + ocol[j] - (zrow[i] + zcol[j]);
            }
        }
        return res;
    }
};