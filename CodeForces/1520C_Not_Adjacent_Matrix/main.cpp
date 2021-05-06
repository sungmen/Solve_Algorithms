#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        if (n == 2) {
            cout << -1 << '\n'; continue;
        } else {
            int tmp = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << tmp << ' ';
                    tmp += 2;
                    if (tmp > n * n) {
                        tmp = 2;
                    }
                }
                cout << '\n';
            }
        }
    }
    return 0;
}