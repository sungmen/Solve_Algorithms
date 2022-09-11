class Solution 
{
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) 
	{
        map<pair<int, int>, int> m;
        int pos[8][2] = {{0, 1}, {0, -1}, {-1, 0}, {-1, 1}, {-1, -1}, {1, 0}, {1, -1}, {1, 1}};
        for (auto q : queens)
        {
            m[{q[0], q[1]}] = 1;
        }
        vector<vector<int>> res;
        for (int i = 0; i < 8; i++)
        {
            pair<int, int> cur = {king[0], king[1]};
            while (cur.first >= 0 && cur.first < 8 && cur.second >= 0 && cur.second < 8)
            {
                if (m[{cur.first, cur.second}])
                {
                    res.push_back({cur.first, cur.second});
                    break;
                }
                
                cur.first += pos[i][0];
                cur.second += pos[i][1];
            }
        }
        
        return res;
    }
};