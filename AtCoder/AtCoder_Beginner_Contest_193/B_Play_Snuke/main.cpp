#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    int MIN = 1e9+1;
    for (int i = 0; i < n; i++) {
        int a, p, x; cin >> a >> p >> x;
        if (a < x && MIN > p) {
            MIN = p;
        }
    }
    if (MIN == 1e9+1) {
        cout << -1;
    } else {
        cout << MIN;
    }
    return 0;
}