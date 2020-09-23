#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;

int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, k, x; cin >> n >> m >> k >> x;
    vector<pair<int, int>> v[n+1];
    int d[n+1];
    for (int i = 1 ; i <= n; i++) d[i] = INF;
    for (int i =0 ; i < m ; i++) {
        int a, b; cin >> a >> b;
        v[a].emplace_back(b, 1);
    }

    d[x] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(x, 0));
    while(!pq.empty()) {
        int cur = pq.top().first;
        int dis = -pq.top().second;
        pq.pop();
        if(d[cur] < dis) continue;
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int nextDis = dis + v[cur][i].second;
            if (nextDis < d[next]) {
                d[next] = nextDis;
                pq.push(make_pair(next, -nextDis));
            }
        }
    }
    vector<int> vv;
    for (int i = 1; i <= n ; i++) {
        if (d[i] == k) {
            vv.emplace_back(i);
        }
    }
    if(vv.empty()) {
        cout << -1;
    } else {
        for(auto i : vv) cout << i << '\n';
    }
    return 0;
}