#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int p = pow(n, 1/2.);
        int pp = pow(n, 1/3.);
        int ppp = pow(pp, 1/2.);
        if (n == 1000000000) cout << p + pp - ppp + 1 << '\n';
        else cout << p + pp - ppp << '\n';
    }
    return 0;
}
