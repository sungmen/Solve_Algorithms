#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        string str; cin >> str;
        sort(str.begin(), str.end());
        cout << str << '\n';
    }
    return 0;
}
