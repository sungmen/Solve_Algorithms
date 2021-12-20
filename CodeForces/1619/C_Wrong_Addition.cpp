#include <bits/stdc++.h>
using namespace std;
long long ans;
void dfs(string a, string b, string a2, string b2, string res) {
    if (a2.size() > 0 && b2.size() > 0) {
        if (b2.size() > 1 && b2[0] == '0') return;
        int ib = stoi(b2);
        int ia = stoi(a2);
        if (ib - ia >= 0 && ib - ia < 10) {
            string tmp = to_string(ib-ia);
            res = tmp + res;
        } else {
            return;
        }
    }
    if (a == "" || b == "") {
        if(res == "") return;
        if (a == "" && b == "") {
            ans = stoll(res);
        } else if (a == "") {
            res = b+res;
            ans = stoll(res);
        }
        return;
    }
    dfs(a.substr(0, a.size()-1), b.substr(0, b.size()-1), a.substr(a.size()-1), b.substr(b.size()-1), res);
    if (b.size() > 1) dfs(a.substr(0, a.size()-1), b.substr(0, b.size()-2), a.substr(a.size()-1), b.substr(b.size()-2), res);
}
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        string a, b; cin >> a >> b;
        ans = -1;
        dfs(a, b, "", "", "");
        if (ans == -1) cout << -1 << '\n';
        else {
            cout << ans << '\n';
        }
    }
    return 0;
}
