#include <bits/stdc++.h>
using namespace std;
struct th {
    int y, x, cnt;
};
int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int w, h; cin >> w >> h;
        vector<string> v(h);
        vector<vector<bool>> chk(h, vector<bool>(w, false)), fMap(h, vector<bool>(w, false));
        queue<pair<int,int>> f;
        queue<th> q;
        for (int i = 0; i < h; i++) {
            cin >> v[i];
            for (int j = 0; j < w; j++) {
                if (v[i][j] == '*') {
                    f.push({i, j});
                    fMap[i][j] = 1;
                }
                else if (v[i][j] == '@') {
                    q.push({i, j, 1});
                    chk[i][j] = 1;
                }
            }
        }
        bool chkO = false;
        while(!q.empty()) {
            int fSize = f.size();
            while(fSize--) {
                pair<int, int> cur = f.front();
                f.pop();
                for (int i = 0; i < 4; i++) {
                    pair<int, int> next = {cur.first + pos[i][0], cur.second + pos[i][1]};
                    if (next.first >= 0 && next.first < h && next.second >= 0 && next.second < w && !fMap[next.first][next.second] && v[next.first][next.second] != '#') {
                        fMap[next.first][next.second] = 1;
                        f.push({next.first, next.second});
                    }
                }
            }
            int qSize = q.size();
            while (qSize--) {
                th cur = q.front();
                q.pop();
                if (cur.y == 0 || cur.y == h - 1 || cur.x == 0 || cur.x == w - 1) {
                    chkO = true;
                    cout << cur.cnt << '\n';
                    break;
                }
                for (int i = 0; i < 4; i++) {
                    pair<int, int> next = {cur.y + pos[i][0], cur.x + pos[i][1]};
                    if (next.first >= 0 && next.first < h && next.second >= 0 && next.second < w && v[next.first][next.second] != '#' && !fMap[next.first][next.second] && !chk[next.first][next.second]) {
                        chk[next.first][next.second] = 1;
                        q.push({next.first, next.second, cur.cnt + 1});
                    }
                }
            }
            if (chkO) break;
        }
        if (!chkO) cout << "IMPOSSIBLE" << '\n';

    }
    return 0;
}