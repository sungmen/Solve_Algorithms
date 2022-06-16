class Solution 
{
public:
    
    struct th
    {
        int y, x;
    };
    
    int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int maxDistance(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int ans = -1;
        queue<th> q;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    q.push({i, j});
                }
            }
        }
        
        while (!q.empty())
        {
            ans++;
            int t = q.size();
            
            while (t--)
            {
                th cur = q.front();
                q.pop();                
                for (int i = 0; i < 4; i++)
                {
                    th next = {cur.y + pos[i][0], cur.x + pos[i][1]};
                    if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n || 0 != grid[next.y][next.x]) continue;
                    
                    grid[next.y][next.x] = 1;
                    q.push(next);
                }
            }
        }
        
        if (-1 == ans || 0 == ans) return -1;
        return ans;
    }
};