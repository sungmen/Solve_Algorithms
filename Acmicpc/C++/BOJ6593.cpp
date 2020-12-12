#include <bits/stdc++.h>
using namespace std;
char d[31][31][31];
bool chk[31][31][31];
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int pos[6][3] = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};
    while (1) {
        int l, r, c; 
        cin >> l >> r >> c;
        if (!l && !r && !c) return 0;
        queue<pair<pair<int, int>, pair<int, int>>> q;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                string str; cin >> str;
                for (int k = 0; k < c; k++) {
                    d[i][j][k] = str[k];
                    if (d[i][j][k] == 'S') {
                        q.push({{0, i}, {j, k}});
                        chk[i][j][k] = 1;
                    }
                }
            }
        }
        memset(chk, false, sizeof(chk));
        bool bo = false;
        int time_v = 0;
        while (!q.empty()) {
            pair<pair<int, int>, pair<int, int>> cur = q.front();
            q.pop();
            if (d[cur.first.second][cur.second.first][cur.second.second] == 'E') {
                cout << "Escaped in " << cur.first.first << " minute(s).\n";
                bo = true;
                break;
            }
            for (int i = 0; i < 6; i++) {
                pair<pair<int, int>, pair<int, int>> next = {{cur.first.first+1, cur.first.second+pos[i][0]}, {cur.second.first+pos[i][1], cur.second.second+pos[i][2]}};
                if (next.first.second < 0 || next.first.second >= l || next.second.first < 0 || next.second.first >= r || next.second.second < 0 || next.second.second >= c || chk[next.first.second][next.second.first][next.second.second] || d[next.first.second][next.second.first][next.second.second] == '#') continue;
                chk[next.first.second][next.second.first][next.second.second] = 1;
                q.push({{next.first.first, next.first.second}, {next.second.first, next.second.second}});
            }
        }
        if (!bo) cout << "Trapped!\n";
    }
    return 0;
}