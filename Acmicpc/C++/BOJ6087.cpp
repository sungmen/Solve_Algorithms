#include <bits/stdc++.h>
using namespace std;
const int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
struct th {
    int y, x, dic, cnt;
};
int chk[101][101];
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int w, h; cin >> w >> h;
    vector<string> v(h);
    vector<pair<int, int>> poi;
    for (int i = 0; i < 101; i++) for (int j = 0; j < 101; j++) chk[i][j] = INT_MAX;
    for (int i = 0; i < h; i++) {
        cin >> v[i];
        for (int j = 0; j < w; j++) {
            if (v[i][j] == 'C') {
                poi.push_back({i, j});
            }
        }
    }
    queue<th> q;
    for (int i = 0; i < 4; i++) q.push({poi[0].first, poi[0].second, i, 0});
    chk[poi[0].first][poi[0].second] = 0;
    while(!q.empty()) {
        th cur = q.front();
        // cout << cur.y << ' ' << cur.x << ' ' << cur.res << '\n';
        q.pop();
        for (int i = 0; i < 4; i++) {
            th next = {cur.y + pos[i][0], cur.x + pos[i][1], cur.dic, cur.cnt};
            if (next.y < 0 || next.y >= h || next.x < 0 || next.x >= w || v[next.y][next.x] == '*') continue;
            if (next.dic != i) next.cnt += 1;
            if (chk[next.y][next.x] >= next.cnt) {
                chk[next.y][next.x] = next.cnt;
                next.dic = i;
                q.push(next);
            }
        }
    }
    cout << chk[poi[1].first][poi[1].second];
    return 0;
}
