#include <bits/stdc++.h>
using namespace std;
const int POS [4][2] = {{0 ,1}, {0, -1}, {1, 0}, {-1, 0}};
typedef struct POINT {
    int x, y, sum;
} P;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    int d[n][m];
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        for (int j = 0; j < m; j++) {
            d[i][j] = int(str[j])-48;
        }
    }
    int chk[n][m];
    memset(chk, 0, sizeof(chk));
    queue<P> q;
    q.push({0, 0, 1});
    chk[0][0] = 1;
    while (!q.empty()) {
        P p = q.front();
        q.pop();
        if (p.x == n - 1 && p.y == m - 1) {
            cout << p.sum;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int x_ = p.x + POS[i][0];
            int y_ = p.y + POS[i][1];
            if (x_ < 0 || x_ >= n || y_ < 0 || y_ >= m) continue;
            if (d[x_][y_] && !chk[x_][y_]) {
                chk[x_][y_] = 1;
                q.push({x_, y_, p.sum + 1});
            }
        }
    }
}