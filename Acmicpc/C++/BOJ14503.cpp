#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, r, c, d; cin >> n >> m >> r >> c >> d;
    int arr[n][m];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> arr[i][j];
    pair<int, int> cur = {r, c};
    bool chk[n][m];
    memset(chk, false, sizeof(chk));
    chk[r][c] = 1;
    int res = 1;
    pair<int, int> pos[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int rot[4][4] = {{3, 2, 1, 0}, {0, 3, 2, 1}, {1, 0, 3, 2}, {2, 1, 0, 3}};
    while(1) {
        bool next_move = true;
        for (int i = 0; i < 4; i++) {
            if(!chk[cur.first+pos[rot[d][i]].first][cur.second+pos[rot[d][i]].second] && !arr[cur.first+pos[rot[d][i]].first][cur.second+pos[rot[d][i]].second]) {
                chk[cur.first+pos[rot[d][i]].first][cur.second+pos[rot[d][i]].second] = 1;
                cur = {cur.first+pos[rot[d][i]].first, cur.second+pos[rot[d][i]].second};
                d = rot[d][i];
                next_move = false;
                res++;
                break;
            }
        }
        if(next_move) {
            if (!arr[cur.first+pos[rot[d][1]].first][cur.second+pos[rot[d][1]].second]) {
                cur = {cur.first+pos[rot[d][1]].first, cur.second+pos[rot[d][1]].second};
            } else {
                cout << res;
                return 0;
            }
        }
    }
    return 0;
}