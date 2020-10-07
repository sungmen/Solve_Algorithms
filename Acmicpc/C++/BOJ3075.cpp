#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int main(){
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    for(cin>>t;t--;) {
        int n, p, q; cin >> n >> p >> q;
        int dn[n];
        for (int i = 0; i < n; i++) cin >> dn[i];
        int d[p+1][p+1];
        for(int i = 0; i <= p; i++) for (int j = 0; j <= p; j++) d[i][j] = INF;
        for (int i = 0; i < q; i++) {
            int a, b, c; cin >> a >> b >> c;
            if(d[a][b] > c) {
                d[a][b] = c;
            }
            if(d[b][a] > c) {
                d[b][a] = c;
            }
        }        
        for (int k = 1; k <= p; k++) for (int i = 1; i <= p; i++) for (int j = 1; j <= p; j++) if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
        for (int i = 1; i <= p; i++) d[i][i] = 0;
        long long min_v = LLONG_MAX, res = 0;
        for (int i = 1; i <= p; i++) {
            long long sum = 0;
            for (int j = 0; j < n; j++) {
                sum += (d[dn[j]][i] * d[dn[j]][i]);
            }
            if(min_v > sum) {
                min_v = sum;
                res = i;
            }
        }
        cout << res << ' ' << min_v << '\n';
    }
    return 0;
}