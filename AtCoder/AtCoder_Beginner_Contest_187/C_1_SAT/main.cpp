#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    map<string, string> m;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        string tmp; cin >> tmp;
        if (tmp[0] == '!') {
            v.emplace_back(tmp);
        } else {
            m.insert(pair<string, string>('!'+tmp, tmp));
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (m.find(v[i]) != m.end()) {
            cout << m.find(v[i]) -> second;
            return 0;
        }
    }
    cout << "satisfiable";
    return 0;
}
