#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int v, e, i; cin >> v >> e;
        vector<int> vv[v+1], vc(v+1, 0);
        bool chk = true;
        int a, b;
        for (i = 0; i < e; i++) {
            cin >> a >> b;
            if (a == b) continue;
            vv[a].push_back(b);
            vv[b].push_back(a);
        }
        for (i = 1; i <= v; i++) {
            if (!vc[i]) {
                vc[i] = 1;
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int cur = q.front();
                    q.pop();
                    for (int j = 0; j < vv[cur].size(); j++) {
                        if (!vc[vv[cur][j]]) {
                            if (vc[cur]==1) vc[vv[cur][j]] = 2;
                            else vc[vv[cur][j]] = 1;
                            q.push(vv[cur][j]);
                        } else if (vc[cur] == vc[vv[cur][j]]) {
                            chk = false;
                            break;
                        }
                    }
                    if (!chk) break;
                }
                if (!chk) break;
            }
        }
        cout << (chk ? "YES" : "NO") << '\n';
    }
    return 0;
}