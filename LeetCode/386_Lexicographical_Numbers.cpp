class Solution 
{
public:
    vector<int> lexicalOrder(int n) 
    {
        map<string, int> m;
        vector<int> vi;
        for (int i = 1; i <= n; i++)
        {
            m[to_string(i)] = i;
        }
        for (auto it = m.begin(); it != m.end(); it++)
        {
            vi.push_back(it->second);
        }
        return vi;
    }
};