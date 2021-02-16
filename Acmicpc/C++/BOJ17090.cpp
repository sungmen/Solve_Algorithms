#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n ; ++i) {
        string str;
        cin >> str;
        for (int j = 0; j < m; ++j) {
            v[i][j] = str[j];
        }
    }
    int ans = 0;
    vector<vector<bool>> chk(n, vector<bool>(m, false)), chk_true(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!chk[i][j]) {
                queue<pair<int,int>> q;
                int res = 0;
                q.push({i, j});
                stack<pair<int,int>> stk;
                while(!q.empty()) {
                    pair<int, int> cur = q.front();
                    if (cur.first < 0 || cur.first >= n || cur.second < 0 || cur.second >= m || chk_true[cur.first][cur.second]) {
                        ans += res;
                        while(!stk.empty()) {
                            chk_true[stk.top().first][stk.top().second] = true;
                            stk.pop();
                        }
                        break;
                    }
                    if(chk[cur.first][cur.second]) {
                        break;
                    }
                    res++;
                    chk[cur.first][cur.second] = true;
                    q.pop();
                    stk.push({cur.first, cur.second});
                    if(v[cur.first][cur.second] == 'D') {
                        q.push({cur.first+1, cur.second});
                    } else if(v[cur.first][cur.second] == 'U') {
                        q.push({cur.first-1, cur.second});
                    } else if(v[cur.first][cur.second] == 'L') {
                        q.push({cur.first, cur.second-1});
                    } else if(v[cur.first][cur.second] == 'R') {
                        q.push({cur.first, cur.second+1});
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}