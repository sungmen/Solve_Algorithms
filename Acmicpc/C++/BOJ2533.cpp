#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 1;
vector<int> vi[MAX];
pair<int,int> dp[MAX];
vector<bool> chk(MAX, false);
void dfs(int idx) {
    chk[idx] = 1;
    dp[idx].first = 0;
    dp[idx].second = 1;
    for (int i = 0; i < vi[idx].size(); i++) {
        if (chk[vi[idx][i]]) continue;
        dfs(vi[idx][i]);
        dp[idx].first += dp[vi[idx][i]].second;
        dp[idx].second += min(dp[vi[idx][i]].first, dp[vi[idx][i]].second);
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    while(n--) {
        int u, v; cin >> u >> v;
        vi[u].push_back(v);
        vi[v].push_back(u);
    }
    dfs(1);
    cout << min(dp[1].first, dp[1].second);
    return 0;
}