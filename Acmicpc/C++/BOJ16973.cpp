#include <bits/stdc++.h>
using namespace std;
int v[1001][1001];
int res[1001][1001];
int h, w, sr, sc, fr, fc;
bool chkY(int y, int x) {
    for (int i = y; i <= y + h; i++) {
        if (v[i][x] == 1) {
            return false;
        }
    }
    return true;
}
bool chkX(int y, int x) {
    for (int i = x; i <= x + w; i++) {
        if (v[y][i] == 1) {
            return false;
        }
    }
    return true;
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    cin >> h >> w >> sr >> sc >> fr >> fc;
    h--, w--, sr--, sc--, fr--, fc--;
    memset(res, -1, sizeof(res));
    int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    queue<pair<int, int>> q;
    q.push({sr, sc});
    res[sr][sc] = 0;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if (cur.first == fr && cur.second == fc) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            pair<int, int> next = {cur.first + pos[i][0], cur.second + pos[i][1]};
            if (next.first >= 0 && next.first < n-h && next.second >= 0 && next.second < m-w && v[next.first][next.second] != 1 && res[next.first][next.second] == -1) {
                switch(i) {
                    case 0: {
                        if (chkY(cur.first, next.second + w)) {
                            res[next.first][next.second] = res[cur.first][cur.second] + 1;
                            q.push(next);
                        }
                        break;
                    }
                    case 1: {
                        if (chkY(cur.first, next.second)) {
                            res[next.first][next.second] = res[cur.first][cur.second] + 1;
                            q.push(next);
                        }
                        break;
                    }
                    case 2: {
                        if (chkX(next.first + h, cur.second)) {
                            res[next.first][next.second] = res[cur.first][cur.second] + 1;
                            q.push(next);
                        }
                        break;
                    }
                    case 3: {
                        if (chkX(next.first, cur.second)) {
                            res[next.first][next.second] = res[cur.first][cur.second] + 1;
                            q.push(next);
                        }
                        break;
                    }
                }
            }
        }
    }
    cout << res[fr][fc];
    return 0;
}