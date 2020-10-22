#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    for (int test_c = 1; test_c <= t; test_c++) {
        string str; cin >> str;
        string ans = "";
        for (int i = str.size()-1; i >= 0; i--) {
            if (str[i] == 'b') ans += 'd';
            if (str[i] == 'd') ans += 'b';
            if (str[i] == 'p') ans += 'q';
            if (str[i] == 'q') ans += 'p';
        }
        cout << '#' << test_c << ' ' << ans << '\n';
    }
}