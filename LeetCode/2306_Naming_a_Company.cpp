class Solution 
{
public:
    long long distinctNames(vector<string>& ideas) 
    {
        set<string> um[26];
        for (auto it : ideas) 
        {
            um[it[0]-'a'].insert(it.substr(1));
        }
        long long idx = 0;
        for (int i = 0; i < 26; i++)
        {
            for (int j = i + 1; j < 26; j++)
            {
                long long idx1 = 0, idx2 = 0;
                for (auto it : um[i])
                {
                    if (um[j].find(it) == um[j].end())
                    {
                        idx1++;
                    }
                }
                for (auto it : um[j])
                {
                    if (um[i].find(it) == um[i].end())
                    {
                        idx2++;
                    }
                }
                idx += idx1 * idx2;
            }
        }
        return idx * 2;
    }
};