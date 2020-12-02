#include <bits/stdc++.h>
using namespace std;
int main(){
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int row, col; cin >> row >> col;
    int d[row][col];
    int before = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> d[i][j];
            if (d[i][j] == 1) before++;
        }
    }
    int af = before, ti = 0;
    int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (1) {
        ti++;
        bool chk[row][col];
        memset(chk, false, sizeof(chk));
        queue<pair<int, int>> q;
        q.push({0, 0});
        chk[0][0] = 1;
        while(!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                pair<int, int> next = {cur.first + pos[i][0], cur.second + pos[i][1]};
                if (next.first < 0 || next.first >= row || next.second < 0 || next.second >= col || chk[next.first][next.second]) continue;
                chk[next.first][next.second] = 1;
                if (d[next.first][next.second]) {
                    d[next.first][next.second] = 0;
                    af--;
                    continue;
                }
                q.push({next.first, next.second});
            }
        }
        if (af == 0) break;
        before = af;
    }
    cout << ti << '\n' << before;
    return 0;
}