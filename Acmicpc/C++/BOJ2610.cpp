#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n;
    int d[n+1][n+1];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) d[i][j] = INF;
    for (cin >> m; m--; ) {
        int a, b; cin >> a >> b;
        d[a][b] = 1;
        d[b][a] = 1;
    }
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
    int chk[n+1];
    memset(chk, 0, sizeof(chk));
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if(chk[i] == 0) {
            queue<int> q;
            chk[i] = 1;
            int max_v = 0;
            int nextAns = i;
            for (int j = 1; j <= n; j++) {
                if (d[i][j] > 0 && d[i][j] <1e8) {
                    if (max_v < d[i][j]) max_v = d[i][j];
                    chk[j] = 1;
                    q.push(j);
                }
            }
            while(!q.empty()) {
                int cur = q.front();
                q.pop();
                int tmp_v = 0;
                for (int j = 1; j <= n; j++) {
                    if(d[cur][j] > 0 && d[cur][j] < 1e8) {
                        if(tmp_v < d[cur][j]) tmp_v = d[cur][j];
                    }
                }
                if(max_v > tmp_v) {
                    max_v = tmp_v;
                    nextAns = cur;
                }
            }
            ans.emplace_back(nextAns);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << '\n';
}