class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0, n = grid.size(), m = grid[0].size(), pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m ; ++j) {
                if (grid[i][j]) {
                    int cnt = 0;
                    for (int k = 0; k < 4; ++k) {
                        pair<int, int> next = {i + pos[k][0], j + pos[k][1]};
                        if (next.first >= 0 && next.first < n && next.second >= 0 && next.second < m && grid[next.first][next.second]) {
                            ++cnt;
                        }
                    }
                    res += 4 - cnt;
                }
            }
        }
        return res;
    }
};