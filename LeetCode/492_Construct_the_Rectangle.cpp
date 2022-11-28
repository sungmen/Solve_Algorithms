class Solution 
{
public:
    vector<int> constructRectangle(int area) 
    {
        int cur = sqrt(area);
        while (area % cur) 
        {
            cur--;
        }
        return {area/cur, cur};
    }
};