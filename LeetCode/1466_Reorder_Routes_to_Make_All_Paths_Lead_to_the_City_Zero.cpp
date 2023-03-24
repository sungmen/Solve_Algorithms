class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        map<pair<int, int>, int> connec;
        unordered_map<int, vector<int>> um;
        for (auto connect : connections)
        {
            connec[{connect[0], connect[1]}] = 1;
            um[connect[0]].push_back(connect[1]);
            um[connect[1]].push_back(connect[0]);
        }
        queue<int> q;
        q.push(0);
        vector<int> chk(n, false);
        chk[0] = 1;
        int res = 0;
        while (! q.empty())
        {
            int cur = q.front();
            q.pop();
            for (auto ne : um[cur])
            {
                if (chk[ne]) continue;
                if (connec[{cur, ne}]) ++res;
                chk[ne] = 1;
                q.push(ne);
            }
        }
        return res;
    }
};
