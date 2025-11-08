#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    for (cin >> t; t--; ) {
        int p = 0, q = 0;
        int ans = 0;
        string str; cin >> str;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') p++;
            if (str[i] == '[') q++;
            if (str[i] == ')' && p) {
                p--;
                ans++;
            } 
            if (str[i] == ']' && q) {
                q--;
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}