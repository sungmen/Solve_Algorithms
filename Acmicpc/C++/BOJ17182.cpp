#include <bits/stdc++.h>
using namespace std;
int d[11][11];
bool chk[11];
int ans = INT_MAX, n;
void dfs(int k, int res, int p) {
    if (ans < res) return;
    if(p == n) {
       if(ans > res) {
           ans = res;
       }
       return;
    }
    for (int i = 0; i < n; i++) {
        if (!chk[i]) {
            chk[i] = true;
            dfs(i, res+d[k][i], p+1);
            chk[i] = false;
        }
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int k; 
    cin >> n >> k;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> d[i][j];
    for (int m = 0; m < n; m++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (d[i][m] + d[m][j] < d[i][j]) d[i][j] = d[i][m] + d[m][j];
    chk[k] = true;
    dfs(k, 0, 1);    
    cout << ans;
    return 0;
}