#include <bits/stdc++.h>
using namespace std;
struct point {
    int x;
    int y;
} P;
int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, x1, y1, x2, y2; cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    x1--;y1--;x2--;y2--;
    char d[n][m];
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        for (int j = 0; j < m; j++) {
            d[i][j] = str[j];
        }
    }
    int res = 0;
    while(1) {
        bool chk[n][m];
        memset(chk, 0, sizeof(chk));
        queue<point> q;
        q.push({x1, y1});
        chk[x1][y1] = 1;
        while(!q.empty()) {
            point cur = q.front();
            q.pop();
            if (cur.x == x2 && cur.y == y2) {
                cout << res;
                return 0;
            }
            for (int i = 0; i < 4; i++) {
                point next = {cur.x + pos[i][0], cur.y + pos[i][1]};
                if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m || chk[next.x][next.y]) continue;
                chk[next.x][next.y] = 1;
                if (d[next.x][next.y] == '0' ) {
                    q.push(next);
                } else {
                    d[next.x][next.y] = '0';
                }
            }
        }
        res++;
    }
    return 0;
}