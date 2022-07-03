class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> cp = matrix;
        int len = matrix.size();
        int l = 0;
        int r = len - 1;
        for (int i = 0; i < len; i++) {
            l = 0;
            for (int j = 0; j < len; j++) {
                matrix[l++][r] = cp[i][j];
            }
            r--;
        }
        return matrix;
    }
};