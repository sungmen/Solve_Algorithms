class th
{
public:
    int y, x, n;
};

class Solution 
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
    {
        int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        vector<vector<bool>> chk(m, vector<bool>(n, 0));
        queue<th> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isWater[i][j])
                {
                    q.push({i, j, 0});
                    chk[i][j] = 1;
                }
            }
        }
        while (! q.empty())
        {
            th cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                th next = {pos[i][0] + cur.y, pos[i][1] + cur.x, cur.n + 1};
                if (next.y < 0 || next.y >= m || next.x < 0 || next.x >= n || chk[next.y][next.x]) continue;
                chk[next.y][next.x] = 1;
                res[next.y][next.x] = next.n;
                q.push(next);
            }
        }
        return res;
    }
};