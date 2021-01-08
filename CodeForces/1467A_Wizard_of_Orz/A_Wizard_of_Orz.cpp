#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    for (cin >> t; t--; ) {
        int n; cin >> n;
        string str = "";
        if (n == 1) {
            cout << 9 << '\n';
            continue;
        } else if (n == 2) {
            cout << 98 << '\n';
            continue;
        } else {
            str += '9'; 
            str += '8';
            for (int i = 2; i < n; i++) {
                if (str[i-1] == '9') str += '0';
                else str += (str[i-1] + 1);
            }
            cout << str << '\n';
        }
    }
    return 0;
}