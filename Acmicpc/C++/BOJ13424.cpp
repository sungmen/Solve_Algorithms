#include<bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;cin>>t;
    for(int test=0; test<t;test++){
        int n, m; cin >> n >> m;
        int d[n+1][n+1];
        memset(d,10000, (n+1)*(n+1)*4);
        for(int i = 1; i <= n; i++) d[i][i] = 0;
        for(int test_c=0; test_c<m;test_c++){
            int a, b, c; cin >> a >> b >> c;
            d[a][b] = c;
            d[b][a] = c;
        }
        for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
        int k; cin >> k;
        int dk[k];
        for(int i = 0; i < k; i++) cin >> dk[i];
        int max_v = INT_MAX;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int sum = 0;
            for (int j = 0; j < k; j++) {
                sum += d[i][dk[j]];
            }
            if (max_v > sum) {
                max_v = sum;
                res = i;
            }
        }
        cout << res << '\n';
    }
    return 0;
}