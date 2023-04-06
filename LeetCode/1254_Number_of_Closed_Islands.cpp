class Solution 
{
public:
    vector<vector<int>> g;
    bool chk[101][101];
    void dfs(bool& cn, int y, int x)
    {
        if (y < 0 || y >= g.size() || x < 0 || x >= g[0].size() || chk[y][x] == 1 || g[y][x] == 1) return;
        if (y == 0 || y == g.size() - 1 || x == 0 || x == g[0].size() - 1) cn = false;
        chk[y][x] = 1;
        dfs(cn, y-1,x);
        dfs(cn, y+1,x);
        dfs(cn, y,x-1);
        dfs(cn, y,x+1);
    }

    int closedIsland(vector<vector<int>>& grid) 
    {
        int res = 0;
        g = grid;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if (0 != grid[i][j] || false != chk[i][j]) continue;
                bool cn = 1;
                dfs(cn, i, j);
                if (cn) res++;
            }
        }
        return res;
    }
};