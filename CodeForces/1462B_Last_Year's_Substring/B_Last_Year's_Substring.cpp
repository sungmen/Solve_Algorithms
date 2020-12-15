#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    for (cin >> t ; t--; ) {
        int n; cin >> n;
        string str; cin >> str;
        if (n < 4) {
            cout << "NO" << '\n';
        }
        else {
            if (!str.compare(0, 4, "2020")) {
                cout << "YES" << '\n';
            } else if (!str.compare(n-4, 4, "2020")) {
                cout << "YES" << '\n';
            } else if (str[0] == '2' && str[1] == '0' && str[2] == '2' && str[n-1] == '0') {
                cout << "YES" << '\n';
            } else if (str[0] == '2' && str[1] == '0' && str[n-2] == '2' && str[n-1] == '0') {
                cout << "YES" << '\n';
            } else if (str[0] == '2' && str[n-3] == '0' && str[n-2] == '2' && str[n-1] == '0') {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}