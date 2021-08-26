#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, x; cin >> n >> m >> x;
    vector<vector<vector<pair<int, int>>>> vp(2, vector<vector<pair<int,int>>>(n+1));
    vector<vector<int>> dist(2, vector<int>(n+1, INT_MAX));
    dist[0][x] = 0;
    dist[1][x] = 0;
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        vp[0][a].emplace_back(b, c);
        vp[1][b].emplace_back(a, c);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int t = 0; t < 2; ++t) {
        pq.emplace(0, x);
        while (!pq.empty()) {
            pair<int, int> cur = pq.top();
            pq.pop();
            for (int i = 0; i < vp[t][cur.second].size(); ++i) {
                pair<int, int> next = {cur.first + vp[t][cur.second][i].second, vp[t][cur.second][i].first};
                if (dist[t][next.second] > next.first) {
                    dist[t][next.second] = next.first;
                    pq.emplace(next);
                }
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < dist[0].size(); ++i) {
        answer = (answer < dist[0][i] + dist[1][i] ? dist[0][i] + dist[1][i] : answer);
    }
    cout << answer;
    return 0;    
}