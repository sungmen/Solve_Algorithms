#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int d[26][26];
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int m, n; cin >> m >> n;
    for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++) d[i][j] = INF;
    for (int i = 0; i < 26; i++) d[i][i] = 0;
    for (int i = 0; i < m; i++) {
        char a, b; cin >> a >> b;
        d[int(a)-97][int(b)-97] = 1;
    }
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        string a, b; cin >> a >> b;
        if (a.length() != b.length()) {
            cout << "no" << '\n';
        }
        else {
            int chk = 1;
            for (int i = 0; i < a.length(); i++) {
                if (d[int(a[i])-97][int(b[i])-97] == INF) {
                    chk = 0;
                    break;
                }
            }
            if(chk) {
                cout << "yes" << '\n';
            }
            else {
                cout << "no" << '\n';
            }
        }
    }
}