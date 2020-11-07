#include <bits/stdc++.h>
using namespace std;
const int POS[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
typedef struct Point {
    int x, y, s, b;
} P;
int chk[1001][1001][2];
int d[1001][1001];
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        for (int j = 0; j < m; j++) {
            d[i][j] = int(str[j]) - '0';
        }
    }
    queue<P> q;
    q.push({0, 0, 1, 0});
    chk[0][0][0] = 1;
    chk[0][0][1] = 1;
    while(!q.empty()) {
        P cur = q.front();
        q.pop();
        if (cur.x == n-1 && cur.y == m-1) {
            cout << cur.s;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int x_ = cur.x + POS[i][0];
            int y_ = cur.y + POS[i][1];
            int block = cur.b;
            if (x_ < 0 || x_ >= n || y_ < 0 || y_ >= m) continue;
            if(chk[x_][y_][cur.b]) continue;
            if(d[x_][y_] && cur.b) continue;
            if (d[x_][y_]) {
                block = 1;
                chk[cur.x][cur.y][1] = 1;
                q.push({x_, y_, cur.s + 1, block});
            } else {
                chk[x_][y_][cur.b] = 1;
                q.push({x_, y_, cur.s + 1, block});
            } 
        }
    }
    cout << -1;
    return 0;
}