class Solution {
private:
    vector<vector<int>> v[101];
    
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        vector<bool> chk(n, false);
        for(auto flight : flights) {
            v[flight[0]].push_back({flight[1], flight[2]});
        }
        queue<pair<int, int>> q;
        q.push({0, src});
        dist[src] = 0;
        ++k;
        while (!q.empty()) {
            int si = q.size();
            if (--k < 0) break;
            for (int i = 0; i < si; ++i) {
                pair<int, int> cur = q.front();
                q.pop();
                for (auto j : v[cur.second]) {
                    if (j[1] + cur.first < dist[j[0]]) {
                        dist[j[0]] = j[1] + cur.first;
                        q.push({dist[j[0]], j[0]});
                    }
                }
            }
        }
        return (dist[dst] == INT_MAX ? -1 : dist[dst]);
    }
};