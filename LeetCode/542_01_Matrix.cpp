class Solution 
{
public:
    struct th
    {
        int y, x, c;
    };

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> chk(n, vector<int>(m, 0));
        int pos[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
                queue<th> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (0 != mat[i][j]) continue;
                q.push({i, j, 0});
            }
        }
        while (!q.empty())
        {
            th cur = q.front();
            q.pop();
            int c = 1;
            int si = q.size();
            for (int k = 0; k < 4; k++)
            {
                int y_ = cur.y + pos[k][0];
                int x_ = cur.x + pos[k][1];
                int c_ = cur.c + 1;
                if (y_ < 0 || y_ >= n || x_ < 0 || x_ >= m || 0 == mat[y_][x_] || (c_ >= ans[y_][x_] && 0 != ans[y_][x_])) continue;
                ans[y_][x_] = c_;
                q.push({y_,x_,c_});
            }
        }
        return ans;
    }
};