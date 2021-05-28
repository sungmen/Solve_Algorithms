class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int cnt = 0, m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) if (matrix[i][0]) cnt++;
        for (int i = 1; i < n; i++) if (matrix[0][i]) cnt++;
        for (int i = 1; i < m; i++) {
             for (int j = 1; j < n; j++) {
                 if (matrix[i][j]) {
                     matrix[i][j] += min(matrix[i-1][j], min(matrix[i][j-1], matrix[i-1][j-1]));
                     cnt += matrix[i][j];
                 }
             }
        }
        return cnt;
    }
};