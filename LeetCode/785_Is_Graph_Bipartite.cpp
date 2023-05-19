class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> chk(graph.size(), 0);
        vector<bool> black(graph.size(), 0);
        for (int c = 0; c < graph.size(); c++)
        {
            if (chk[c]) continue;
            black[c] = 1;
            queue<int> q;
            q.push(c);
            while (! q.empty())
            {
                int cur =q.front();
                vector<int> v = graph[cur];
                q.pop();
                bool blk = black[cur];
                for (auto i : v)
                {
                    if(chk[i])
                    {
                        if (blk == black[i])
                            return false;
                        continue;
                    }
                    q.push(i);
                    black[i] = (blk?0:1);
                    chk[i] = 1;
                }
            }
        }


        return true;
    }
};