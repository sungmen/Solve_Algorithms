class Solution 
{
public:
    int projectionArea(vector<vector<int>>& grid) 
    {
        int xy = 0;
        int xz = 0;
        int yz = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            int c = 0;
            int p = 0;
            for (int j = 0; j < grid[0].size(); j++)
            {
                c = max(c, grid[i][j]);
                p = max(p, grid[j][i]);
                if (grid[i][j] != 0) xy++;
            }
            xz += c;
            yz += p;
        }
        return xy + xz + yz;
    }
};