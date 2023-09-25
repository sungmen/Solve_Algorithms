class Solution 
{
public:
    double champagneTower(int poured, int query_row, int query_glass) 
    {
        vector<vector<double>> d(query_row + 3, vector<double>(query_row+3));
        d[0][0] = (double)poured;
        for (int i = 0; i <= query_row + 1; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                double r = 0.0;
                if (d[i][j] > 1)
                {
                    r = d[i][j] - 1;
                    d[i][j] = 1;
                }
                d[i+1][j] += r / 2;
                d[i+1][j+1] += r / 2;
            }
        }
        return d[query_row][query_glass];
    }
};