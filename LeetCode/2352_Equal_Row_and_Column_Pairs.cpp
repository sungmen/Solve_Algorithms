class Solution 
{
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        int ans = 0, m = grid.size();
        map<vector<int>, int> r, c;
        for (int i = 0; i < m; i++)
        {
            c[grid[i]]++;
        }
        for (int i = 0; i < m; i++)
        {
            vector<int> t;
            for (int j = 0; j < m; j++)
            {
                t.push_back(grid[j][i]);
            }
            r[t]++;
        }
        for (auto it = r.begin(); it != r.end(); it++)
        {
            auto f = c.find(it->first);
            if (f != c.end())
            {
                ans += f->second * it->second;
            }
        }
            
        return ans;
    }
};