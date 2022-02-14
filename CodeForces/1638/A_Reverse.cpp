#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n+1);
        bool chk = true;
        int find = 0;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            if (chk && v[i] != i) {
                find = i;
                chk = false;
            }
            if (!chk && find == v[i]) {
                int j = i;
                while (find < j) {
                    swap(v[find], v[j]);
                    find++, j--;
                }
                find = 0;
            }
        }
        for (int i = 1; i <= n; i++) cout << v[i] << ' ';
        cout << '\n';
    }
    return 0;
}
