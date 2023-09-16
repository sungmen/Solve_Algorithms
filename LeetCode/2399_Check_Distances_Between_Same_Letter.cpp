class Solution 
{
public:
    bool checkDistances(string s, vector<int>& distance) 
    {
        unordered_map<char, int> um;
        bool chk = 1;
        for (int i = 0; i < s.size(); i++)
        {
            if (um.find(s[i]) == um.end())
            {
                um[s[i]] = i;
                continue;
            }
            int c = um[s[i]];
            if (distance[s[i]-'a'] != (i - c - 1)) return 0;
        }
        return 1;
    }
};