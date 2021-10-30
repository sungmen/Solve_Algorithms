#include <bits/stdc++.h>
using namespace std;
const int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, count; cin >> n >> count;
    vector<string> str(n);
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
    }
    bool chk = true;
    vector<pair<int,int>> v;
    while(chk) {
        chk = false;
        vector<vector<bool>> schk(n, vector<bool>(10, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                if (str[i][j] != '0' && !schk[i][j]) {
                    v.clear();
                    queue<pair<int,int>> q;
                    q.push({i ,j});
                    v.push_back({i, j});
                    schk[i][j] = 1;
                    while (!q.empty()) {
                        pair<int,int> cur = q.front();
                        q.pop();
                        for (int k = 0; k < 4; ++k) {
                            pair<int,int> next = {cur.first + pos[k][0], cur.second + pos[k][1]};
                            if (next.first >= 0 && next.first < n && next.second >= 0 && next.second < 10 && !schk[next.first][next.second] && str[next.first][next.second] == str[i][j]) {
                                q.push(next);
                                schk[next.first][next.second] = 1;
                                v.push_back(next);
                            }
                        }
                    }
                    if (v.size() >= count) {
                        chk = 1;
                        for (auto vp : v) {
                            str[vp.first][vp.second] = '0';
                        }
                    }
                }
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < 10; ++j) {
                if (str[i][j] != '0') {
                    int y = i, x = j;
                    while (y < n - 1) {
                        if (str[y + 1][x] == '0') {
                            swap(str[y + 1][x], str[y][x]);
                            y = y + 1;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << str[i][j];
        }
        cout << '\n';
    }
    return 0;
}
