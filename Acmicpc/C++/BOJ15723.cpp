#include <bits/stdc++.h>
using  namespace std;
const int INF = 1e8;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int d['z'-'a'+1]['z'-'a'+1];
    for (int i = 0; i <= 'z'-'a'; i++) {
        for (int j = 0; j <= 'z'-'a'; j++) {
            d[i][j] = INF;
        }
    }
    for (int i = 0; i <= 'z'-'a'; i++) d[i][i] = 1;
    int n;
    for (cin >> n; n--;) {
        char a, b; string str; cin >> a >> str >> b;
        d[int(a)-'a'][int(b)-'a'] = 1;
    }
    for (int k = 0; k <= 'z'-'a'; k++) {
        for (int i = 0; i <= 'z'-'a'; i++) {
            for (int j = 0; j <= 'z'-'a'; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    int m;
    for  (cin >> m; m--;) {
        char a, b; string str; cin >> a >> str >> b;
        if (d[int(a)-'a'][int(b)-'a'] != INF) cout << 'T' << '\n';
        else cout << 'F' << '\n';
    }
    return 0;
}