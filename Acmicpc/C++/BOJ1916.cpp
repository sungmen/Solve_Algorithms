#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MAX = INT_MAX;
int dist[1001];
vector<pi> vp[1001];
void dijkstra(int s) {
    dist[s] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, s));
    while(!pq.empty()) {
        int cur = pq.top().second;
        int dis = -pq.top().first;
        pq.pop();
        if (dist[cur] < dis) continue;
        for (int i = 0; i < vp[cur].size(); i++) {
            int next = vp[cur][i].first;
            int next_dis = dis + vp[cur][i].second;
            if (dist[next] > next_dis) {
                dist[next] = next_dis;
                pq.push(make_pair(-next_dis, next));
            }
        }
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) dist[i] = MAX;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        vp[u].emplace_back(make_pair(v, w));
    }
    int s, e; cin >> s >> e;
    dijkstra(s);
    cout << dist[e];
    return 0;
}