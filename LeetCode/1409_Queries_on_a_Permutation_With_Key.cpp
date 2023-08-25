class Solution 
{
public:
    vector<int> processQueries(vector<int>& queries, int n) 
    {
        map<int, int> m;
        for (int i = 1; i <= n; i++)
        {
            m[i] = i - 1;
        }

        for (auto i = 0; i < queries.size(); i++)
        {
            int cur = queries[i];
            queries[i] = m[queries[i]];
            for (auto j : m)
            {
                if (j.second <= queries[i])
                {
                    m[j.first]++;
                }
            }
            m[cur] = 0;
        }    
        return queries;
    }
};