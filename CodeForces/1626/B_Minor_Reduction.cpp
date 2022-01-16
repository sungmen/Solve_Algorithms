#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        string str; cin >> str;
        int i = 0;
        bool chk = 1;
        for (i = str.size()-2; i >= 0; --i) {
            if ((str[i]-'0'+str[i+1]-'0') > 9) {
                chk = 0;
                break;
            }
        }
        if (chk) {
            cout << to_string(str[0]-'0'+str[1]-'0') + str.substr(2) << '\n';
        } else {
            cout << str.substr(0, i) + to_string((str[i]-'0'+str[i+1]-'0')) + str.substr(i+2) << '\n';
        }
    }
    return 0;
}
