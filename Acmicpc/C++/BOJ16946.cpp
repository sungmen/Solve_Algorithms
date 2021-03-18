#include <bits/stdc++.h>
using namespace std;
const int POS[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> v(n, vector<pair<int,int>>(m));
    vector<vector<pair<int,int>>> v2(n, vector<pair<int,int>>(m, {0,0}));
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        for (int j = 0; j < m; j++) {
            v[i][j] = {-1, (str[j] - '0')};
        }
    }
    v2 = v;
    vector<vector<bool>> chk(n, vector<bool>(m, false));
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j].second == 0) {
                stack<pair<int, int>> stk;
                queue<pair<int, int>> q;
                q.push({i, j});
                stk.push({i, j});
                int cnt = 1;
                chk[i][j] = true;
                while(!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        pair<int,int> next = {cur.first+POS[k][0], cur.second+POS[k][1]};
                        if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m || chk[next.first][next.second] == true || v[next.first][next.second].second != 0) continue;
                        chk[next.first][next.second] = true;
                        cnt++;
                        stk.push({next.first, next.second});
                        q.push({next.first, next.second});
                    }
                }
                while(!stk.empty()) {
                    v[stk.top().first][stk.top().second] = {count, cnt};
                    stk.pop();
                }
                count++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j].first == -1) {
                map<int, int> map_;
                for (int k = 0; k < 4; k++) {
                    pair<int, int> next = {i + POS[k][0], j + POS[k][1]};
                    if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m || map_[v[next.first][next.second].first]) continue;
                    if (chk[next.first][next.second]) {
                        v2[i][j].second += v[next.first][next.second].second;
                        map_[v[next.first][next.second].first] = 1;
                    } 
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (v2[i][j].second%10);
        }
        cout << '\n';
    }
    return 0;
}