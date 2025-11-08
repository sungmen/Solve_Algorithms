#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        string str; cin >> str;
        if (str.size()%2) {
            cout << "NO\n";
        } else {
            bool chk = true;
            for (int i = 0; i < str.size() / 2; ++i) {
                if (str[i] != str[i+str.size()/2]) {
                    chk = false;
                    break;
                }
            }
            cout << (chk?"YES":"NO") << '\n';
        }
    }
    return 0;
}
