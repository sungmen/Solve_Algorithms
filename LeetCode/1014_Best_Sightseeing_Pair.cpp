class Solution 
{
public:
    int maxScoreSightseeingPair(vector<int>& values) 
    {
        int j = 0;
        int res = 0;
        for (int i = 1; i < values.size(); i++)
        {
            res = max(res, values[i] + values[j] + j - i);
            if (j + values[j] < i + values[i])
            {
                j = i;
            }
        }
        return res;
    }
};