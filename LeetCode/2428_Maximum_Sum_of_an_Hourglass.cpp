class Solution {
public:
    int rowdfs(int sum, int y, int x, vector<vector<int>>& grid)
    {
        return sum - grid[y-2][x-3] - grid[y][x-3] - grid[y-1][x-2] + grid[y][x] + grid[y-2][x] + grid[y-1][x-1];
    }
    int coldfs(int sum, int y, int x, vector<vector<int>>& grid)
    {
        return sum - grid[y-3][x-2] - grid[y-3][x-1] - grid[y-3][x] - grid[y-1][x-2] - grid[y-1][x] + grid[y-2][x-2] + grid[y-2][x] + grid[y][x-2] + grid[y][x-1] + grid[y][x];
    }
    
    int maxSum(vector<vector<int>>& grid) {
        int sum = grid[0][0] + grid[0][1] + grid[0][2] + grid[1][1] + grid[2][0] + grid[2][1] + grid[2][2];
        int res = sum;
        for (int i = 2; i < grid.size(); i++)
        {
            int curi = sum;
            for (int j = 3; j < grid[0].size(); j++)
            {
                sum = rowdfs(sum, i, j, grid);
                res = max(res, sum);
            }
            if (i + 1 < grid.size())
            {
                sum = coldfs(curi, i + 1, 2, grid);
                res = max(res, sum);
            }
        }
        
        return res;        
    }
};