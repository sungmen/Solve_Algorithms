#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int r, c; cin >> r >> c;
    vector<string> str(r);
    struct th{
        int y, x, cnt;
    };
    queue<th> start;
    queue<pair<int, int>> f;
    vector<vector<bool>> chk(r, vector<bool>(c, false)), fi(r, vector<bool>(c, false));
    for (int i = 0; i < r; i++) {
        cin >> str[i];
        for (int j = 0; j < c; j++) {
            if (str[i][j] == 'J') {
                start.push({i, j, 0});
                chk[i][j] = true;
            }
            else if (str[i][j] == 'F') {
                fi[i][j] = true;
                f.push({i, j});
            }
        }
    }
    int pos[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    while(!start.empty()) {
        int fSize = f.size();
        while(fSize--) {
            pair<int, int> cur = f.front();
            f.pop();
            for (int i = 0; i < 4; i++) {
                pair<int, int> next = {cur.first + pos[i][0], cur.second + pos[i][1]};
                if (next.first >= 0 && next.first < r && next.second >= 0 && next.second < c && str[next.first][next.second] != '#' && !fi[next.first][next.second]) {
                    fi[next.first][next.second] = true;
                    f.push(next);
                }
            }
        }
        int startSize = start.size();
        while(startSize--) {
            th cur = start.front();
            start.pop();
            if (cur.y < 0 || cur.y >= r || cur.x < 0 || cur.x >= c) {
                cout << cur.cnt;
                return 0;
            }
            for (int i = 0; i < 4; i++) {
                th next = {cur.y + pos[i][0], cur.x + pos[i][1], cur.cnt + 1};
                if (next.y >= 0 && next.y < r && next.x >= 0 && next.x < c) {
                    if (str[next.y][next.x] != '#' && !chk[next.y][next.x] && !fi[next.y][next.x]) {
                        chk[next.y][next.x] = true;
                        start.push(next);
                    }
                } else {
                    start.push(next);
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}