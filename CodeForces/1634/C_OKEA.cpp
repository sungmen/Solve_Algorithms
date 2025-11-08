#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        if (k > 1 && (n%2)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int cnt = 1;
            for (int i = 0; i < n; i++) {
                int m = cnt;
                for(int j = 0; j < k; j++) {
                    cout << (m)<< ' ';
                    m += n;
                }
                cnt++;
                cout << '\n';
            }            
        }
    }
    return 0;
}
