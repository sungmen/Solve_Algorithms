class Solution 
{
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) 
    {
        int b = -1, res = 0;
        for (auto rec : rectangles)
        {
            int minLen = min(rec[0], rec[1]);
            if (minLen == b)
                res++;
            if (minLen > b)
            {
                b = minLen;
                res = 1;
            }
        }
        return res;
    }
};