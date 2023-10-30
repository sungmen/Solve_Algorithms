class Solution {
public:
  int pos[8][2] = {{0, 1}, {0, -1}, {1, 1},   {1, -1},
                   {1, 0}, {-1, 1}, {-1, -1}, {-1, 0}};
  void gameOfLife(vector<vector<int>> &board) {
    int m = board.size(), n = board[0].size();
    vector<vector<int>> chk(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int arround = 0;
        for (int k = 0; k < 8; k++) {
          int ny = i + pos[k][0];
          int nx = j + pos[k][1];
          if (ny < 0 || ny >= m || nx < 0 || nx >= n)
            continue;
          if (board[ny][nx] == 1)
            arround++;
        }
        if (board[i][j] && arround != 2 && arround != 3)
          chk[i][j] = 1;
        if (!board[i][j] && arround == 3)
          chk[i][j] = -1;
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (1 == chk[i][j])
          board[i][j] = 0;
        else if (-1 == chk[i][j])
          board[i][j] = 1;
      }
    }
  }
};
