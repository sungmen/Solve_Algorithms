class Solution 
{
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<pair<int, int>> v(n + 1, {0, 0});
        
        for (auto t : trust)
        {
            v[t[0]].first++;
            v[t[1]].second++;
        }
        for (int idx = 1; idx <= n; idx++)
        {
            if (!v[idx].first && n-1 == v[idx].second)
                return idx;
        }
        
        return -1;
    }
};