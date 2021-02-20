#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string str; cin >> str;
    bool chk = true;
    for (int i = 0; i < str.size(); i++) {
        if (!(i%2)) {
            if (str[i]>='A' && str[i]<='Z') {
                chk = false;
                break;
            }
        } else {
            if (str[i]>='a'&&str[i]<='z'){
                chk=false;
                break;
            }
        }
    }
    if (chk) cout << "Yes";
    else cout << "No";

    return 0;
}