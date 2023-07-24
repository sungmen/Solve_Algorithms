class Solution 
{
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) 
    {
        int n = matrix.size(), m = matrix[0].size();
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[i][j] = (i > 0 && j > 0 ? matrix[i][j]^matrix[i-1][j-1] : matrix[i][j]);
                matrix[i][j] = (i > 0 ? matrix[i][j]^matrix[i-1][j]:matrix[i][j]);
                matrix[i][j] = (j > 0 ? matrix[i][j]^matrix[i][j-1]:matrix[i][j]);
                pq.push(-matrix[i][j]);
                if (pq.size() > k)
                {
                    pq.pop();
                }
            }
        }
        return -pq.top();
    }
};