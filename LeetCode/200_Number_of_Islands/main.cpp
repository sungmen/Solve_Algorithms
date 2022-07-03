class Solution {
private:
    const int MOV[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> chk(m, vector<bool>(n, false));
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!chk[i][j] && grid[i][j] == '1') {
                    cnt++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    chk[i][j] = true;
                    while (!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();
                        for (int i = 0; i < 4; i++) {
                            pair<int, int> next = {cur.first + MOV[i][0], cur.second + MOV[i][1]};
                            if (next.first < 0 || next.first >= m || next.second < 0 || next.second >= n || chk[next.first][next.second] || grid[next.first][next.second] == '0') continue;
                            q.push(next);
                            chk[next.first][next.second] = true;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};