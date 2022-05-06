class Solution 
{
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) 
    {
        map<double, long long> m;
        for (auto rectangle : rectangles)
        {
            m[(double)rectangle[0]/rectangle[1]] ++;
        }
        long long res = 0;
        for (auto it : m)
        {
            if (it.second == 1) continue;
            res += (it.second * (it.second-1)) / 2;
        }
        return res;
    }
};