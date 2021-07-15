#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    map<pair<int, int>, vector<pair<int, int>>> ma;
    map<pair<int, int>, int> chk, move, move_chk;
    for (int i = 0; i < m; i++) {
        int x, y, a, b; cin >> x >> y >> a >> b;
        ma[make_pair(x, y)].push_back({a, b});
    }
    const int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({1, 1});
    chk[{1, 1}] = 1;
    move[{1, 1}] = 1;
    move_chk[{1, 1}] = 1;
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pair<int, int> next = {cur.first+pos[i][0], cur.second+pos[i][1]};
            if (next.first >= 1 && next.first <= n && next.second >= 1 && next.second <= n && !move[{next.first, next.second}]) {
                move[{next.first, next.second}] = 1;
            }
        }
        for (auto it = ma[{cur.first, cur.second}].begin(); it != ma[{cur.first, cur.second}].end(); ++it) {
            if (!chk[{it->first, it->second}]) {
                chk[{it->first, it->second}] = 1;
                cnt++;
                if (move[{it->first, it->second}] && !move_chk[{it->first, it->second}]) {
                    move_chk[{it->first, it->second}] = 1;
                    q.push({it->first, it->second});
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            pair<int, int> next = {cur.first+pos[i][0], cur.second+pos[i][1]};
            if (next.first >= 1 && next.first <= n && next.second >= 1 && next.second <= n && chk[{next.first, next.second}] &&move[{next.first, next.second}] && !move_chk[{next.first, next.second}]) {
                move_chk[{next.first, next.second}] = 1;
                q.push({next.first, next.second});
            }
        }
    }
    cout << cnt;
    return 0;
}