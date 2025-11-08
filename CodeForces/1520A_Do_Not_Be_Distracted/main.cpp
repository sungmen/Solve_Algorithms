#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    while(n--) {
        int t; cin >> t;
        string str; cin >> str;
        vector<int> num(26, 0);
        bool chk = true;
        for (int i = 0; i < t; i++) {
            if (num[str[i]-'A'] && str[i] != str[i-1]) {
                chk = false;
                break;
            } else {
                num[str[i]-'A']++;
            }
        }
        cout << (chk?"YES":"NO") << '\n';
    }
    return 0;
}