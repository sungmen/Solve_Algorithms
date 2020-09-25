#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<pair<int, int> > v[n+1];
    int d[n+1];
    for(int i = 1; i <= n ; i++) d[i] = INF;
    for (int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        v[x].emplace_back(y, z);
        v[y].emplace_back(x, z);
    }
    d[1] = 0;
    priority_queue<pair<int, int> >pq;
    pq.push(make_pair(1, 0));
    while(!pq.empty()) {
        int cur = pq.top().first;
        int dis = -pq.top().second;
        pq.pop();
        if (d[cur] < dis) continue;
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int nextDis = dis + v[cur][i].second;
            if (nextDis < d[next]) {
                d[next] = nextDis;
                pq.push(make_pair(next, -nextDis));
            }
        }
    }
    cout << d[n];
    return 0;
}