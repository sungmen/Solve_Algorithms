class Solution {
public:
    void dfs(int idx, int cnt, vector<int>& edges, vector<int>& dist)
    {
        dist[idx] = cnt;
        if (edges[idx] == -1 || dist[edges[idx]] != -1) return;
        dfs(edges[idx], cnt + 1, edges, dist);
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int res = 1e9;
        int resedge = -1;
        vector<int> dist1(edges.size(), -1);
        vector<int> dist2(edges.size(), -1);
        dfs(node1, 0, edges, dist1);
        dfs(node2, 0, edges, dist2);
        for (int i = 0; i < edges.size(); i++)
        {
            if (dist1[i] != -1 && dist2[i] != -1 && res > max(dist1[i], dist2[i]))
            {
                res = max(dist1[i], dist2[i]);
                resedge = i;
            }
        }
        return resedge;
    }
};