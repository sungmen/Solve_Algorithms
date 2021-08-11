#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<pair<int, int>>> tmp;
    vector<vector<bool>> chk(n, vector<bool>(n, false));
    const int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int index = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!chk[i][j] && v[i][j])  {
                queue<pair<int, int>> q;
                q.push({i, j});
                chk[i][j] = 1;
                while(!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    int cnt = 0;
                    for (int i = 0;  i < 4; ++i) {
                        pair<int, int> next = {cur.first + pos[i][0], cur.second + pos[i][1]};
                        if (next.first >= 0 && next.first < n && next.second >= 0 && next.second < n && v[next.first][next.second]) {
                            ++cnt;
                            if (!chk[next.first][next.second]) {
                                chk[next.first][next.second] = 1;
                                q.push({next.first, next.second});
                            }
                        }
                    }
                    if ((cur.first == 0 || cur.first == n - 1) && (cur.second == 0 || cur.second == n - 1)) {
                        if (cnt != 2) {
                            if (tmp.size() < index) {
                                vector<pair<int, int>> vpii = {{cur.first, cur.second}};
                                tmp.push_back(vpii);
                            } else tmp[index-1].push_back({cur.first, cur.second});
                        }
                    } else if ((cur.first == 0 || cur.first == n - 1)) {
                        if (cnt != 3) {
                            if (tmp.size() < index) {
                                vector<pair<int, int>> vpii = {{cur.first, cur.second}};
                                tmp.push_back(vpii);
                            } else tmp[index-1].push_back({cur.first, cur.second});
                        }
                    } else if (cur.second == 0 || cur.second == n - 1) {
                        if (cnt != 3) {
                            if (tmp.size() < index) {
                                vector<pair<int, int>> vpii = {{cur.first, cur.second}};
                                tmp.push_back(vpii);
                            } else tmp[index-1].push_back({cur.first, cur.second});
                        }
                    } else {
                        if (cnt != 4) {
                            if (tmp.size() < index) {
                                vector<pair<int, int>> vpii = {{cur.first, cur.second}};
                                tmp.push_back(vpii);
                            } else tmp[index-1].push_back({cur.first, cur.second});
                        }
                    }
                }
                ++index;
            }
        }
    }
    int res = INT_MAX;
    for (int i = 0; i < tmp.size() - 1; ++i) {
        for (int j = i + 1; j < tmp.size(); ++j) {
            for (int k = 0; k < tmp[i].size(); ++k) {
                for (int l = 0; l < tmp[j].size(); ++l) {
                    int t = abs(tmp[i][k].first-tmp[j][l].first) + abs(tmp[i][k].second-tmp[j][l].second) - 1;
                    res = t < res ? t : res;
                }
            }
        }
    }
    cout << res;
    return 0;
}