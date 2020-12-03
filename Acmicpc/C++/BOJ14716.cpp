#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int pos[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    int m, n; cin >> m >> n;   
    int d[m][n];
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> d[i][j];
    bool chk[m][n];
    memset(chk, false, sizeof(chk));
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] && !chk[i][j]) {
                ans++;
                chk[i][j] = 1;
                queue<pair<int, int>> q;
                q.push({i, j});
                while(!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int k = 0; k < 8; k++) {
                        pair<int, int> next = {cur.first + pos[k][0], cur.second + pos[k][1]};
                        if (next.first < 0 || next.first >= m || next.second < 0 || next.second >= n || !d[next.first][next.second] || chk[next.first][next.second]) continue;
                        chk[next.first][next.second] = 1;
                        q.push({next.first, next.second});
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}