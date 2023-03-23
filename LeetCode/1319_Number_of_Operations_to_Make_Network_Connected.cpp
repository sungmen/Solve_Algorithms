class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n - 1 > connections.size()) return -1;
        unordered_map<int, vector<int>> um;
        for (auto con : connections)
        {
            um[con[0]].push_back(con[1]);
            um[con[1]].push_back(con[0]);
        }
        vector<bool> chk(n, 0);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (chk[i]) continue;
            ++res;
            chk[i] = 1;
            queue<int> q;
            q.push(i);
            while (! q.empty())
            {
                int cur = q.front();
                q.pop();
                for (auto next : um[cur])
                {
                    if (chk[next]) continue;
                    chk[next] = 1;
                    q.push(next);
                }
            }
        }
        return res - 1;
    }
};