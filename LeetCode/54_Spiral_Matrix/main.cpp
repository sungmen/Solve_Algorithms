class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if (m == 1) return matrix[0];
        vector<int> res;
        if (n == 1) {
            for (int i = 0; i < m; i++) res.push_back(matrix[i][0]);
            return res;
        }
        vector<vector<bool>> chk(m, vector<bool>(n, false));
        int y = 0, x = 0, d = 0;
        
        while(1) {
            if (d == 0) {
                chk[y][x] = true;
                res.push_back(matrix[y][x]);
                if (x + 1 >= n || chk[y][x+1]) {
                    d = 1;
                    if (chk[y+1][x]) break;
                    y++;
                } else {
                    x++;
                }
            } else if (d == 1) {
                chk[y][x] = true;
                res.push_back(matrix[y][x]);
                if (y + 1 >= m || chk[y+1][x]) {
                    d = 2;
                    if (chk[y][x-1]) break;
                    x--;
                } else {
                    y++;
                }
            } else if (d == 2) {
                chk[y][x] = true;
                res.push_back(matrix[y][x]);
                if (x - 1 < 0 || chk[y][x-1]) {
                    d = 3;
                    if (chk[y-1][x]) break;
                    y--;
                } else {
                    x--;
                }
            } else if (d == 3) {
                chk[y][x] = true;
                res.push_back(matrix[y][x]);
                if (y - 1 < 0 || chk[y-1][x]) {
                    d = 0;
                    if (chk[y][x+1]) break;
                    x++;
                } else {
                    y--;
                }
            }
        }
        
        return res;
    }
};