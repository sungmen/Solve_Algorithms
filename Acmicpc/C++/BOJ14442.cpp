#include <bits/stdc++.h>
using namespace std;
const int POS[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
struct th {
    int y, x, k;
};
int chk[1001][1001][11];
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int i = 0, j = 0;
    queue<th> q;
    q.push({0, 0, 0});
    chk[0][0][0] = 1;
    while(!q.empty()) {
        th cur = q.front();
        q.pop();
        if (cur.y == n-1 && cur.x == m-1) {
            cout << chk[cur.y][cur.x][cur.k];
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            pair<int, int> next = {cur.y + POS[i][0], cur.x + POS[i][1]};
            if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m) continue;
            if (v[next.first][next.second] == '0' && !chk[next.first][next.second][cur.k]) {
                chk[next.first][next.second][cur.k] = chk[cur.y][cur.x][cur.k]+1;
                q.push({next.first, next.second, cur.k});
            } else if (v[next.first][next.second] == '1' && cur.k < k && !chk[next.first][next.second][cur.k+1]) {
                chk[next.first][next.second][cur.k+1] = chk[cur.y][cur.x][cur.k]+1;
                q.push({next.first, next.second, cur.k + 1});
            }  
        }
    }
    cout << -1;
    return 0;
}