class Solution 
{
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        int m = edges.size();
        vector<double> ans(n, 0.0);
        vector<bool> check(n, false);
        vector<vector<pair<int, double>>> v(n);
        priority_queue<pair<double, int>> pq;
        ans[start] = 1.0;
        pq.push({1.0, start});
        for (int i = 0; i < m; i++)
        {
            v[edges[i][0]].push_back({edges[i][1], succProb[i]});
            v[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        while (!pq.empty())
        {
            double a = pq.top().first;
            int b = pq.top().second;
            pq.pop();
            if (true == check[b]) continue;
            check[b] = true;
            for (int i = 0; i < v[b].size(); i++)
            {
                int c = v[b][i].first;
                double d = v[b][i].second;
                double next = d * a;
                if (ans[c] >= next) continue;
                ans[c] = next;
                pq.push({next, c});
            }
        }
        return ans[end];
    }
};