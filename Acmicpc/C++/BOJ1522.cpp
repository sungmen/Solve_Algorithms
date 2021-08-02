#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string str; cin >> str;
    int a = 0, res = str.size(), b = 0;
    for (auto s : str) if (s == 'a') ++a;
    for (int i = 0; i < str.size(); ++i) {
        b = 0;
        for (int j = i; j < a + i; ++j) {
            if (str[j % str.size()] == 'b') ++b;
        }
        res = min(res, b);
    }
    cout << res;
    return 0;
}