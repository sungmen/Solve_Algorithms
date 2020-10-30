#include <bits/stdc++.h>
using namespace std;
struct poi {
    int x;
    int y;
};
const int INF = 1e9;
int pos[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int v[126][126];
int res[126][126];
bool chk[126][126];
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int tc = 1;
    while(1) {
        int t; cin >> t;
        if(!t) return 0;
        for (int i = 0; i < t; i++) for (int j = 0; j < t; j++) res[i][j] = INF;
        for (int i = 0; i < t; i++) for (int j = 0; j < t; j++) cin >> v[i][j];
        memset(chk, false, sizeof(chk));
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        res[0][0] = v[0][0];
        while(!q.empty()) {
            struct poi p = {q.front().first, q.front().second};
            q.pop();
            for (int i = 0; i < 4; i++) {
                struct poi p_ = {p.x + pos[i][0], p.y + pos[i][1]};
                if (p_.x >= 0 && p_.x < t && p_.y >= 0 && p_.y < t && !chk[p_.x][p_.y]) {
                    if (res[p_.x][p_.y] > res[p.x][p.y] + v[p_.x][p_.y]) {
                        res[p_.x][p_.y] = res[p.x][p.y] + v[p_.x][p_.y];
                        q.push(make_pair(p_.x, p_.y));
                    }
                }
            }
        }
        cout << "Problem " << tc++ << ": " << res[t-1][t-1] << '\n';
    }
}