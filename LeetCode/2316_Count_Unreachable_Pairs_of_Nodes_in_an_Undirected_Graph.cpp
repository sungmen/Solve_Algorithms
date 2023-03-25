class Solution 
{
public:
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        vector<bool> chk(n, 0);
        long long res = 0;
        unordered_map<int, vector<int>> um;
        for (auto edge : edges)
        {
            um[edge[0]].push_back(edge[1]);
            um[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < n; i++)
        {
            if (chk[i]) continue;
            chk[i] = 1;
            queue<int> q;
            q.push(i);
            map<int, int> m;
            m[i] = 1;
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                for (auto u : um[cur])
                {
                    if (chk[u]) continue;
                    chk[u] = 1;
                    m[u] = 1;
                    q.push(u);
                }
            }
            for (auto it = m.begin(); it != m.end(); it++)
            {
                res += (n - it->first - m.size());
                m.erase(m.begin());
            }
        }
        return res;
    }
};
