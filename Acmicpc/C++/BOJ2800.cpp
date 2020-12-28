#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string str; cin >> str;
    stack <int> stk;
    vector<pair<int, int>> v;
    vector<string> ans;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            stk.push(i);
        } else if (str[i] == ')') {
            if (!stk.empty()) {
                v.push_back({stk.top(), i});
                stk.pop();
            }
        }
    }
    for (int i = 1; i < 1 << v.size(); i++) {
        string tmp = str;
        for (int j = 0; j < v.size(); j++) if (i & (1 << j)) tmp[v[j].first] = tmp[v[j].second] = 'a';
        string cur;
        for (auto j : tmp) if (j != 'a') cur += j;
        ans.push_back(cur);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) if (ans[i-1] != ans[i]) cout << ans[i] << "\n";
    return 0;
}