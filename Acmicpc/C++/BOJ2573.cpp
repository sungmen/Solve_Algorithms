#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    int d[n][m];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> d[i][j];
    int ans = 1, ti = 0;
    int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (ans == 1) {
        ans = 0;
        queue<pair<int, int>> q;
        bool chk_1[n][m];
        memset(chk_1, false, sizeof(chk_1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (d[i][j] && !chk_1[i][j]) {
                    chk_1[i][j] = true;
                    ans++;
                    q.push({i, j});
                    while(!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            pair<int, int> next = {cur.first+pos[k][0], cur.second+pos[k][1]};
                            if (next.first < 0 || next.first >=n || next.second < 0 || next.second >= m || chk_1[next.first][next.second] || !d[next.first][next.second]) continue;
                            q.push({next.first, next.second});
                            chk_1[next.first][next.second] = 1;
                        }
                    }
                }
            }
        }
        if (ans == 0 || ans > 1) break;
        ti++;
        bool chk_2[n][m];
        memset(chk_2, false, sizeof(chk_2));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (d[i][j]) {
                    chk_2[i][j] = 1;
                    for (int k = 0; k < 4; k++) {
                        pair<int, int> next = {i+pos[k][0], j+pos[k][1]};
                        if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m || d[next.first][next.second] || chk_2[next.first][next.second]) continue;
                        if(d[i][j] > 0) d[i][j]--;
                    }
                }
            }
        }
    }
    if (ans == 0) cout << 0;
    else cout << ti;
    return 0;
}