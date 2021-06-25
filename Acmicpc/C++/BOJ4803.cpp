#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int cnt = 1;
    while(1) {
        int n, m, i; cin >> n >> m;
        vector<int> v[n+1];
        vector<bool> chk(n+1, false);
        vector<int> p(n+1, 0);
        if (!n && !m) return 0;
        for (i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            v[a].emplace_back(b);
            v[b].emplace_back(a);
        }
        queue<int> q;
        int res = 0;
        bool chk_r = false;
        for (int i = 1; i <= n; i++) {
            if (!chk[i]) {
                chk_r = true;
                chk[i] = true;
                q.push(i);
                while (!q.empty()) {
                    int cur = q.front();
                    q.pop();
                    for (int j = 0; j < v[cur].size(); j++) {
                        if (chk[v[cur][j]] && p[cur] != v[cur][j]) chk_r = false;
                        else if (chk[v[cur][j]]) continue;
                        else {
                            chk[v[cur][j]] = true;
                            p[v[cur][j]] = cur;
                            q.push(v[cur][j]);
                        }
                    }
                }                
                if(chk_r) ++res;
            }
        }
        cout << "Case " << cnt++ << ": " << (res > 1 ? "A forest of " + to_string(res) + " trees" : (res == 1 ? "There is one tree" : "No trees")) << ".\n";
    }
    return 0;
}