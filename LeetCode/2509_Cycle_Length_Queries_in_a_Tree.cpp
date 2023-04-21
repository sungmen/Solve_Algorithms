class Solution 
{
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) 
    {
        vector<int> ans;
        for (auto query : queries)
        {
            int n1 = query[0];
            int n2 = query[1];
            unordered_map<int, int> um;
            int idx = 1;
            while(n1 != 0)
            {
                um[n1] = idx++;
                n1 = (n1 >> 1);
            }
            int idx2 = 1;
            while (n2 != 0)
            {
                if (um.find(n2) != um.end())
                {
                    ans.push_back(um[n2] + idx2 - 1);
                    break;
                }
                n2 = (n2 >> 1);
                idx2++;
            }

        }
        return ans;
    }
};