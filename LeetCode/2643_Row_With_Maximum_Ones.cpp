class Solution 
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) 
    {
        int maxCol = 0, maxCnt = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            int cnt = 0;
            for (auto m : mat[i])
            {
                if (m == 1) cnt++;
            }
            if (maxCnt < cnt)
            {
                maxCol = i;
                maxCnt = cnt;
            }
        }
        return {maxCol, maxCnt};
    }
};