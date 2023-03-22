class Solution 
{
public:
    int minScore(int n, vector<vector<int>>& roads) 
    {
        int res = INT_MAX;
        unordered_map<int, vector<pair<int, int>>> um;
        for (auto road : roads)    
        {
          um[road[0]].push_back({road[1], road[2]});
          um[road[1]].push_back({road[0], road[2]});
        }
        queue<int> q;
        q.push(1);
        vector<bool> chk(n + 1, 0);
        chk[1] = 1;
        while (! q.empty())
        {
          int cur = q.front();
          q.pop();
          for (auto dist : um[cur])
          {
            res = min(dist.second, res);
            if (chk[dist.first]) continue;
            chk[dist.first] = 1;
            q.push(dist.first);
          }
        }
        return res;
    }
};