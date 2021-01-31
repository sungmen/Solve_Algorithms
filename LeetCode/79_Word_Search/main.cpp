/**
* Runtime: 512 ms, faster than 7.44% of C++ online submissions for Word Search.
* Memory Usage: 116.5 MB, less than 33.18% of C++ online submissions for Word Search.
*/

class Solution {
public:
    struct sol{
        int x;
        int y;
        int cnt;
        vector<vector<bool>> chk;
    };
    vector<vector<char>> board_;
    const int POS[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    bool dfs(int x, int y, int cnt, string word, vector<vector<bool>> chk) {
        if (cnt == word.size() - 1) {
            return true;      
        }
        for (int i = 0; i < 4; i++) {
            pair<int, int> next = {x + POS[i][0], y + POS[i][1]};
            if (next.first < 0 || next.first >= board_.size() || next.second < 0 || next.second >= board_[0].size() || chk[next.first][next.second] || board_[next.first][next.second] != word[cnt + 1]) continue;
            chk[next.first][next.second] = true;
            bool ch = dfs(next.first, next.second, cnt + 1, word, chk);
            if (ch) return true;
            chk[next.first][next.second] = false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        board_ = board;
        queue<sol> q;
        vector<vector<bool>> chk(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    chk[i][j] = true;
                    if (dfs(i, j, 0, word, chk)) return true;                    
                    chk[i][j] = false;
                }
            }
        }
        return false;        
    }
};