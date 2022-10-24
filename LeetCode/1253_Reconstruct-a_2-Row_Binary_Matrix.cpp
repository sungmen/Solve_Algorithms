class Solution 
{
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) 
    {
        vector<int> up(colsum.size(), 0), lo(colsum.size(), 0);
        int col = 0;
        int u = upper, l = lower;
        for (int i = 0; i < colsum.size(); i++)
        {
            col += colsum[i];
            if (colsum[i] == 2)
            {
                if (upper)
                {
                    up[i] = 1;
                    colsum[i]--;
                    upper--;
                } 
                else
                {
                    return {};
                }
                if (lower)
                {
                    lo[i] = 1;
                    colsum[i]--;
                    lower--;
                }
                else
                {
                    return {};
                }
            }
        }
        for (int i = 0; i < colsum.size(); i++)
        {
            if (colsum[i])
            {
                if (upper)
                {
                    up[i] = 1;
                    colsum[i]--;
                    upper--;
                }
            }
            if (colsum[i])
            {
                if (lower)
                {
                    lo[i] = 1;
                    colsum[i]--;
                    lower--;
                }
            }
        }
        if (col != (u + l))
        {
            return {};
        }
        return {up, lo};
    }
};