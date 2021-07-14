#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long long s, t; cin >> s >> t;
    if (s == t) {
        cout << 0;
        return 0;
    }
    const char pos[4] = {'*', '+', '-', '/'};
    unordered_map<long long , int> m;
    queue<pair<long long , string>> q;
    q.push({s, ""});
    m[s] = 1;
    while (!q.empty()) {
        pair<long long , string> cur = q.front();
        q.pop();
        if (cur.first == t) {
            cout << cur.second;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            switch (pos[i]) {
                case '*': {
                    long long  tmp = cur.first * cur.first;
                    if (!m[tmp]) {
                        m[tmp] = 1;
                        q.push({tmp, cur.second + '*'});
                    }
                    break;
                }
                case '+': {
                    long long  tmp = cur.first + cur.first;
                    if (!m[tmp]) {
                        m[tmp] = 1;
                        q.push({tmp, cur.second + '+'});
                    }
                    break;
                }
                case '-': {
                    long long  tmp = cur.first - cur.first;
                    if (!m[tmp]) {
                        m[tmp] = 1;
                        q.push({tmp, cur.second + '-'});
                    }
                    break;
                }
                case '/': {
                    if (cur.first) {
                        long long  tmp = cur.first / cur.first;
                        if (!m[tmp]) {
                            m[tmp] = 1;
                            q.push({tmp, cur.second + '/'});
                        }
                    }
                    break;
                }
            }
        }
    }
    cout << -1;
    return 0;
}