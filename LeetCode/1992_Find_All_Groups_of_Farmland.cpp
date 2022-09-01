class Solution {
public:
    vector<vector<int>> chk;
    pair<int, int> yx_;
    
    void dfs(int y, int x)
    {
        if (y < 0 || y >= chk.size() || x < 0 || x >= chk[0].size() || !chk[y][x]) return;
        chk[y][x] = 0;
        if (yx_.first <= y && yx_.second <= x)
        {
            yx_ = {y, x};
        }
        dfs(y - 1, x);
        dfs(y, x - 1);
        dfs(y + 1, x);
        dfs(y, x + 1);
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        chk = land;
        vector<vector<int>> res;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (chk[i][j])
                {
                    vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back(j);
                    yx_ = {i, j};
                    dfs(i, j);
                    tmp.push_back(yx_.first);
                    tmp.push_back(yx_.second);
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};