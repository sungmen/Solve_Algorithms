class Solution 
{
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int answer = -1;
        int cnt = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    cnt++;
                }
            }
        }
        int pos[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        if (cnt == 0 && q.empty()) return 0;
        while (!q.empty())
        {
            int si = q.size();
            while (si--)
            {
                pair<int, int> cur = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int y_ = cur.first + pos[i][0];
                    int x_ = cur.second + pos[i][1];
                    if (y_ < 0 || y_ >= grid.size() || x_ < 0 || x_ >= grid[0].size() || grid[y_][x_] != 1) continue;
                    grid[y_][x_] = 2;
                    q.push({y_, x_});
                    cnt--;
                }
            }
            answer++;
        }
        cout << cnt;
        return (cnt > 0 ? -1 : answer);
    }
};