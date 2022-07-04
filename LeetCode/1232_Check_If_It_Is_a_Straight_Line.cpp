class Solution 
{
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        if (coordinates.size() == 2) return true;
        
        pair<int, int> p = {coordinates[1][0] - coordinates[0][0], coordinates[1][1] - coordinates[0][1]};
        
        for (int i = 2; i < coordinates.size(); i++)
        {
            pair<int, int> tmp = {coordinates[i][0] - coordinates[0][0] , coordinates[i][1] - coordinates[0][1]};
            if (p.second * tmp.first != p.first * tmp.second) return false;
        }
        
        return true;
    }
};