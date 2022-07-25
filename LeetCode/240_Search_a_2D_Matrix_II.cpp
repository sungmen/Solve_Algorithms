class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size(), m = matrix[0].size();
        int row = n - 1, col = 0;
        
        while (row >= 0 && col < m) 
        {
            if (matrix[row][col] == target) 
            {
                return 1;
            }
            else if (matrix[row][col] > target)
            {
                row--;
            }
            else
            {
                col++;
            }
        }
        return 0;
    }
};