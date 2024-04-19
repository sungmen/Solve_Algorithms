class Solution {
public:
  void dfs(vector<vector<char>> &board, vector<vector<bool>> &chk, int y,
           int x) {
    if (y < 0 || y >= board.size() || x < 0 || x >= board[0].size() ||
        'X' == board[y][x] || true == chk[y][x]) {
      return;
    }
    chk[y][x] = 1;
    dfs(board, chk, y - 1, x);
    dfs(board, chk, y + 1, x);
    dfs(board, chk, y, x - 1);
    dfs(board, chk, y, x + 1);
  }

  void solve(vector<vector<char>> &board) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> chk(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
      if ('O' == board[i][0] && false == chk[i][0]) {
        dfs(board, chk, i, 0);
      }
      if ('O' == board[i][m - 1] && false == chk[i][m - 1]) {
        dfs(board, chk, i, m - 1);
      }
    }
    for (int j = 0; j < m; j++) {
      if ('O' == board[0][j] && false == chk[0][j]) {
        dfs(board, chk, 0, j);
      }
      if ('O' == board[n - 1][j] && false == chk[n - 1][j]) {
        dfs(board, chk, n - 1, j);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ('O' == board[i][j] && false == chk[i][j]) {
          board[i][j] = 'X';
        }
      }
    }
  }
};
