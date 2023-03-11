class Solution 
{
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) 
    {
        map<int, int> m;
        m[INT_MAX] = -1;
        for (int i = 0; i < intervals.size(); i++)
        {
            m[intervals[i][0]] = i;
        }
        vector<int> ans;
        for (auto i : intervals)
        {
            auto it = m.lower_bound(i[1]);
            ans.push_back(it->second);
        }
        return ans;
    }
};