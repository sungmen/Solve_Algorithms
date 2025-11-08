#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    for (cin >> t ; t--; ) {
        int n; cin >> n;
        vector<int> v(n);
        int i;
        for (i = 0; i < n; i++) cin >> v[i];
        int r = n - 1;
        for (i = 0; i < (n / 2); i++) {
            cout << v[i] << ' ';
            cout << v[r-i] << ' ';
        }
        if (n % 2) cout << v[i];
        cout << '\n';
    }
    return 0;
}