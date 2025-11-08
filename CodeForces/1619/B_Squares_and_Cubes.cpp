#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int p = sqrt(n);
        int pp = cbrt(n);
        int ppp = sqrt(pp);
        cout << p + pp - ppp << '\n';
    }
    return 0;
}
