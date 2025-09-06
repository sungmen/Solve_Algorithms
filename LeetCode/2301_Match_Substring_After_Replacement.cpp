class Solution 
{
public:

    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) 
    {
        unordered_map<char, unordered_map<char, int>> um;
        for (auto mapping : mappings)
        {
            um[mapping[0]][mapping[1]] = 1;
        }
        int nSSize = s.size();
        int nSubSize = sub.size();
        
        for (int i = 0; i <= nSSize - nSubSize; i++)
        {
            bool res = true;
            for (int j = i; j < i + nSubSize; j++)
            {
                if (s[j] != sub[j-i] && 1 != um[sub[j-i]][s[j]])
                {
                    res = false;
                }
            }
            if (res)
            {
                return true;
            }
        }
        return false;
    }
};