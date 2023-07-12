class Solution 
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<vector<int>> g(n);
        vector<int> res, cnt(n, 0);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            int t = graph[i].size();
            if (0 == t) 
            {
                res.push_back(i);
                q.push(i);
            }
            cnt[i] = t;
            for (auto j : graph[i])
            {
                g[j].push_back(i);
            }
        }
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (auto i : g[cur])
            {
                if (--cnt[i] == 0)
                {
                    q.push(i);
                    res.push_back(i);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};