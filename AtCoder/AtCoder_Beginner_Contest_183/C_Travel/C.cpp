#include <bits/stdc++.h>
using namespace std;
int ans = 0;
vector<vector<int>> d_;
int K;
void dfs(int sum, vector<bool>& chk, int cnt, int last_n) {
    if (cnt == chk.size()-1) {
        sum += d_[last_n][0];
        if (K == sum) {
            ans++;
        }
        return;
    }
    for (int i = 1; i < chk.size(); i++) {
        if (!chk[i]) {
            chk[i] = 1;
            dfs(d_[last_n][i]+sum, chk, cnt+1, i);
            chk[i] = 0;
        }
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k; cin >> n >> k;
    K = k;
    vector<vector<int>> d(n, vector<int>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> d[i][j];
    d_ = d;
    vector<bool> chk(n, false); 
    chk[0] = 1;
    for (int i = 1; i < n; i++) {
        chk[i] = 1;
        dfs(d[0][i], chk, 1, i);
        chk[i] = 0;
    }
    cout << ans;
}