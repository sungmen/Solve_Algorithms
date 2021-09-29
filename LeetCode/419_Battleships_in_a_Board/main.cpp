class Solution {
private:
    bool chk[201][201];
    vector<vector<char>> b;
    int m, n;
public:
    void dfs(int y, int x) {
        if (y >= 0 && y < m && x >= 0 && x < n && !chk[y][x] && b[y][x] == 'X') {
            chk[y][x] = 1;
            dfs(y+1, x);
            dfs(y, x+1);
            dfs(y-1, x);
            dfs(y, x-1);
        }
    }
    
    int countBattleships(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        b = board;
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!chk[i][j] && board[i][j]=='X') {
                    ++res;
                    dfs(i, j);
                }
            }
        }
        return res;
    }
};