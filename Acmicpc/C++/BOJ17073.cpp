#include <bits/stdc++.h>
using namespace std;
bool chk[500001];
vector<vector<int>> vec(500001);
int cnt = 0;
void dfs(int idx) {
    bool check = 1;
    for (int i = 0; i < vec[idx].size(); ++i) {
        if (!chk[vec[idx][i]]) {
            check = 0;
            chk[vec[idx][i]] = 1;
            dfs(vec[idx][i]);
        }
    }
    if (check) {
        ++cnt;
    }
}
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout.precision(11);
    int n; 
    double w;
    cin >> n >> w;
    chk[1] = 1;
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1);
    cout << (w / cnt);
    return 0;
}
