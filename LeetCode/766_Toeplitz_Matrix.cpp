class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            int num = matrix[i][0];
            int a = i, b = 0;
            while (a < m && b < n)
            {
                if (num != matrix[a][b])
                {
                    return false;
                }
                a++, b++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            int num = matrix[0][i];
            int a = i, b = 0;
            while (a < n && b < m)
            {
                if (num != matrix[b][a])
                {
                    return false;
                }
                a++, b++;
            }
        }
        return true;
    }
};