class Solution 
{
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) 
    {
        vector<vector<int>> net(n, vector<int>(n, 0));
        vector<int> rank(n, 0);
        int res = 0;

        for (auto road : roads)
        {
            rank[road[0]]++;
            rank[road[1]]++;
            if (road[0] < road[1])
                net[road[0]][road[1]] = 1;
            else
                net[road[1]][road[0]] = 1;
        }
        
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                res = max(res, rank[i] + rank[j] - net[i][j]);
            }
        }

        return res;
    }
};