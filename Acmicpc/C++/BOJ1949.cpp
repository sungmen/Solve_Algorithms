#include <bits/stdc++.h>
using namespace std;
#define MAX 1e4 + 1
vector<int> v(MAX);
vector<bool> chk(MAX);
vector<pair<int, int>> vpi(MAX);
vector<vector<int>> vvi(MAX);
void dfs(int cur) {
    vpi[cur].first = 0;
    vpi[cur].second = v[cur];
    for (int i = 0; i < vvi[cur].size(); ++i) {
        if (! chk[vvi[cur][i]]) {
            chk[vvi[cur][i]] = 1;
            dfs(vvi[cur][i]);
            vpi[cur].first += max(vpi[vvi[cur][i]].first, vpi[vvi[cur][i]].second);
            vpi[cur].second += vpi[vvi[cur][i]].first;
        }
    }
}
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> v[i];
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        vvi[a].push_back(b);
        vvi[b].push_back(a);
    }
    chk[1] = 1;
    dfs(1);
    cout << max(vpi[1].first, vpi[1].second);
    return 0;
}
