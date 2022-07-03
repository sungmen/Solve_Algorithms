class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res = 0;
        queue<pair<int,int>> q;
        vector<bool> chk(n);
        chk[headID] = 1;
        q.push({headID, 0});
        vector<vector<int>> v(n);
        for (int i = 0; i < n; i++)
        {
            if (manager[i] != -1)
                v[manager[i]].push_back(i);
        }
        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            if (cur.second > res)
            {
                res = cur.second;
            }
            for (auto i : v[cur.first])
            {
                if (chk[i]) continue;
                chk[i] = 1;
                q.push({i, cur.second + informTime[cur.first]});
            }            
        }
        return res;
    }
};