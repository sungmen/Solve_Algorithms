class Solution {
private:
    const int POS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int, int>> v;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!matrix[i][j]) {
                    v.push_back({i, j});
                }
            }
        }
        for (int i = 0; i < v.size(); i++) {
            pair<int, int> cur = v[i];
            for (int j = 0; j < 4; j++) {
                pair<int, int> next = cur;
                while (1) {
                    next.first += POS[j][0];
                    next.second += POS[j][1];
                    if (next.first < 0 || next.first >= m || next.second < 0 || next.second >= n) break;
                    matrix[next.first][next.second] = 0;
                }
            }
        }
    }
};