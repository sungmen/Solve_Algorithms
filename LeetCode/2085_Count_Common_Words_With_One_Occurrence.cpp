class Solution 
{
public:
    int countWords(vector<string>& words1, vector<string>& words2) 
    {
        int res = 0;
        unordered_map<string, int> um1, um2;
        for (auto it : words1)
        {
            um1[it]++;
        }
        for (auto it : words2)
        {
            um2[it]++;
        }
        for (auto it = um2.begin(); it != um2.end(); it++)
        {
            if (it->second > 1) continue;
            if (um1.find(it->first) == um1.end()) continue;
            int t = um1[it->first];
            if (t > 1) continue;
            res++;
        }

        return res;
    }
};