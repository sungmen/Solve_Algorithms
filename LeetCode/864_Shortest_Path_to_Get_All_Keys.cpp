class Solution 
{
public:
    const int POS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool chk[(1<<6) + 1][31][31];
    struct th
    {
        int y, x, cnt, key, res;
    };

    int shortestPathAllKeys(vector<string>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        queue<th> q;
        int keyCnt = 0;
        map<char, int> keyRel;        
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '@')
                {
                    map<char, int> m;
                    q.push({i, j, 0, 0, 0});
                }
                else if (grid[i][j] >= 'a' && grid[i][j] <= 'z')
                {
                    keyRel[grid[i][j]] = keyCnt;
                    keyRel[grid[i][j]-32] = keyCnt;
                    keyCnt++;
                }
            }
        }
        while (!q.empty())
        {
            th cur = q.front();
            q.pop();
            if (cur.cnt == keyCnt)
                return cur.res;
            for (int i = 0; i < 4; i++)
            {
                int y_ = cur.y + POS[i][0];
                int x_ = cur.x + POS[i][1];
                int cnt_ = cur.cnt;
                int k_ = cur.key;
                int res_ = cur.res;
                if (y_ < 0 || y_ >= row || x_ < 0 || x_ >= col || grid[y_][x_] == '#') continue;
                if (grid[y_][x_] >= 'A' && grid[y_][x_] <= 'Z')
                {
                    int t = (1<<keyRel[grid[y_][x_]]);
                    if ((k_ & t) == 0) continue;
                }
                if (chk[k_][y_][x_]) continue;
                chk[k_][y_][x_] = 1;
                if (grid[y_][x_] >= 'a' && grid[y_][x_] <= 'z')
                {
                    int p = (1<<keyRel[grid[y_][x_]]);
                    if ((k_ & p) == 0)
                    {
                        cnt_++;
                        k_ += p;
                    }
                }
                q.push({y_, x_, cnt_, k_, res_ + 1});
            }
        }
        return -1;
    }
};