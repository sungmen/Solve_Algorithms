#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int k, w, h; cin >> k >> w >> h;
    int d[h][w];
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cin >> d[i][j];
    int pos_horse[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool chk[k+1][h][w];
    memset(chk, false, sizeof(chk)); 
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{0, k}, {0, 0}});
    for(int i = 0; i <= k; i++) chk[i][0][0]=1;
    while(!q.empty()) {
        pair<pair<int, int>, pair<int, int>> cur = q.front();
        q.pop();
        if(cur.second.first == h-1 && cur.second.second == w-1) {
            cout << cur.first.first << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            pair<pair<int, int>, pair<int, int>> next = {{cur.first.first+1, cur.first.second},  {cur.second.first + pos[i][0], cur.second.second + pos[i][1]}};
            if (next.second.first < 0 || next.second.first >= h || next.second.second < 0 || next.second.second >= w || d[next.second.first][next.second.second] || chk[next.first.second][next.second.first][next.second.second]) continue;
            chk[next.first.second][next.second.first][next.second.second] = 1;
            q.push({{next.first.first, next.first.second}, {next.second.first, next.second.second}});
        }
        if (cur.first.second) {
            for (int i = 0; i < 8; i++) {
                pair<pair<int, int>, pair<int, int>> next = {{cur.first.first+1, cur.first.second-1}, {cur.second.first + pos_horse[i][0], cur.second.second + pos_horse[i][1]}};
                if (next.second.first < 0 || next.second.first >= h || next.second.second < 0 || next.second.second >= w || d[next.second.first][next.second.second] || chk[next.first.second][next.second.first][next.second.second]) continue;
                chk[next.first.second][next.second.first][next.second.second] = 1;
                q.push({{next.first.first, next.first.second}, {next.second.first, next.second.second}});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}