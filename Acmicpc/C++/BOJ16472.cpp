#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    string str; cin >> str;
    int l = 0, r = 0, res = 0, cnt = 0;
    vector<int> alp(26, 0);
    while (r < str.size()) {
        if (!alp[(str[r]-'a')]++) ++cnt;
        while(cnt > n) {
            if(!(--alp[(str[l++]-'a')])) --cnt;
        }
        res = max(res, (r++) - l + 1);
    }
    cout << res;
    return 0;
}
