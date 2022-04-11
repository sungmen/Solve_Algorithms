class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        k %= (n * m);
        vector<vector<int>> a(m, vector<int>(n, 0));
        for (int i = 0; i < m * n; i++) {
            int y = i / n, x = i % n, y_ = (y + (x + k) / n) % m, x_ = (x + k) % n;
            a[y_][x_] = grid[y][x];
        }
        return a;
    }
};