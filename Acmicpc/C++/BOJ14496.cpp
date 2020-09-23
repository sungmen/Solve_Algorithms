#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int a, b, n, m; cin >> a >> b >> n >> m;
    vector<pair<int, int> > v[n+1];
    int d[n+1];
    for(int i = 1; i <= n; i++) d[i] = INF;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        v[x].emplace_back(y, 1);
        v[y].emplace_back(x, 1);
    }
    d[a] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(a, 0));
    while(!pq.empty()) {
        int cur = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();
        if (d[cur] < distance) continue;
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int nextDistance = distance + v[cur][i].second;
            if (nextDistance < d[next]) {
                d[next] = nextDistance;
                pq.push(make_pair(next, -nextDistance));
            }
        }
    }
    if(d[b]==INT_MAX) cout << -1;
    else cout << d[b];
    return 0;
}