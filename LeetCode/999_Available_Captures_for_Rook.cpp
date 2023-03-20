class Solution 
{
public:
    int numRookCaptures(vector<vector<char>>& board) 
    {
        int pos[4][2] = {{0, 1},{0,-1},{1,0},{-1,0}};
        pair<int, int> cur = {0, 0};
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if ('R' == board[i][j])
                {
                    cur = {i, j};
                }
            }
        }
        int res = 0;
        for (int i = 0; i < 4; i ++)
        {
            int t = 1;
            int y_ = cur.first + (pos[i][0] * t);
            int x_ = cur.second + (pos[i][1] * t);
            while (y_ >= 0 && y_ < 8 && x_ >= 0 && x_ < 8 && 'B' != board[y_][x_])
            {
                if ('p' == board[y_][x_])
                {
                    res++;
                    break;
                }
                t++;
                y_ = cur.first + (pos[i][0] * t);
                x_ = cur.second + (pos[i][1] * t);
            }
        }
        return res;
    }
};