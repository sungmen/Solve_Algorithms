/**
* Runtime: 48 ms
* Memory Usage: 18.5 MB
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(!m)return {};
        if(m==1) return matrix[0];
        int n = matrix[0].size();
        vector<int> v;
        if(n==1) {
            for (int i = 0; i < m; i++) v.emplace_back(matrix[i][0]);
            return v;
        }
        v.emplace_back(matrix[0][0]);
        int r = 0, c = 1;
        int move_flag = 0;
        while(r != m - 1 || c != n - 1) {
            if(!move_flag) {
                v.emplace_back(matrix[r][c]);
                while(r != m-1 && c != 0) {
                    r++;
                    c--;
                    v.emplace_back(matrix[r][c]);
                }
                if(r == m-1) c++;
                else r++;
                move_flag = true;
            } else {
                v.emplace_back(matrix[r][c]);
                while(r != 0 && c != n-1) {
                    r--;
                    c++;
                    v.emplace_back(matrix[r][c]);
                }
                if(c == n-1) r++;
                else c++;
                move_flag = false;                
            }
        }
        v.emplace_back(matrix[r][c]);
        return v;
    }
};