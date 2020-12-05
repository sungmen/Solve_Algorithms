#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    int d[n][m];
    bool chk[n][m];
    memset(chk, false, sizeof(chk));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d[i][j]; 
            if(d[i][j] == 2) {
                q.push({i, j});
                chk[i][j] = true;
                d[i][j] = 0;
            }            
        }
    }
    int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while(! q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pair<int, int> next = {cur.first + pos[i][0], cur.second + pos[i][1]};
            if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m || chk[next.first][next.second] || !d[next.first][next.second]) continue;
            chk[next.first][next.second] = true;
            d[next.first][next.second] = d[cur.first][cur.second] + 1;
            q.push({next.first, next.second});
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!chk[i][j] && d[i][j]) {
                d[i][j] = -1;
            }
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
}