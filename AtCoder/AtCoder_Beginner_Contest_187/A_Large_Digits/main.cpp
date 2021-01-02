#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string n, m;
    cin >> n >> m;
    int ans = 0;
    int ans2 = 0;
    for (int i = 0; i < 3; i++) {
        ans += (n[i] - '0');
        ans2 += (m[i] -'0');
    }
    cout << (ans > ans2 ? ans : ans2) << endl;
    return 0;
}
