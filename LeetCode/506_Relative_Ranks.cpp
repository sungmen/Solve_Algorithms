class Solution 
{
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        map<int, string> m;
        for (auto s : score)
        {
            m[-s] = "0";
        }
        int n = 1;
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            if (n == 1)
            {
                it->second = "Gold Medal";
            }
            else if (n == 2)
            {
                it->second = "Silver Medal";
            }
            else if (n == 3)
            {
                it->second = "Bronze Medal";
            }
            else
            {
                it->second = to_string(n);
            }
            n++;
        }
        vector<string> ans;
        for (auto s : score)
        {
            ans.push_back(m[-s]);
        }
        return ans;
    }
};