#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> ti;
const int POS[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int m, n; cin >> m >> n;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX)), arr(n, vector<int>(m));
    dist[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        string str; cin >> str;
        for (int j = 0; j < m; ++j) {
            arr[i][j] = str[j] - '0';
        }
    }
    priority_queue<ti> pq;
    pq.emplace(0, 0, 0);
    while (!pq.empty()) {
        auto [v, w, e] = pq.top();
        e = -e;
        pq.pop();
        if (e > dist[v][w]) continue;
        for (int i = 0; i < 4; ++i) {
            pair<int, int> next = {v + POS[i][0], w + POS[i][1]};
            if (next.first >= 0 && next.first < n && next.second >= 0 && next.second < m) {
                int nextV = e + arr[next.first][next.second];    
                if (nextV < dist[next.first][next.second]) {
                    dist[next.first][next.second] = nextV;
                    pq.emplace(next.first, next.second, -nextV);
                }
            }
        }
    }
    cout << dist[n - 1][m - 1];
    return 0;    
}