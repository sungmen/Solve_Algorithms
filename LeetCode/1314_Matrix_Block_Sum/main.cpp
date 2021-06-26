class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> v(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                v[i][j] = mat[i-1][j-1] + v[i-1][j] + v[i][j-1] - v[i-1][j-1];
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int x_1 = i + k, y_1 = j + k, x_2 = i - k - 1, y_2 = j - k - 1;
                if (x_1 > m) x_1 = m;
                if (y_1 > n) y_1 = n;
                if (x_2 < 0) x_2 = 0;
                if (y_2 < 0) y_2 = 0;
                mat[i-1][j-1] = v[x_1][y_1] - v[x_1][y_2] - v[x_2][y_1] + v[x_2][y_2];
            }
        }
        return mat;
    }
};