class Solution 
{
public:
    int minDistance(string word1, string word2) 
    {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) v[i][0] = i;
        for (int i = 1; i <= m; i++) v[0][i] = i;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i-1] == word2[j-1])
                {
                    v[i][j] = v[i-1][j-1];
                }
                else
                {
                    v[i][j] = min(v[i-1][j-1], min(v[i-1][j], v[i][j-1])) + 1;
                }
            }
        }
        return v[n][m];
    }
};