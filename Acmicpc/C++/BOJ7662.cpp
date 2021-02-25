#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int k; cin >> k;
        map<int, int> m;
        while(k--) {
            char chr;
            int tmp; 
            cin >> chr >> tmp;
            if (chr == 'I') {
                if (m.find(tmp) == m.end()) {
                    m[tmp] = 1;
                } else {
                    m.find(tmp)->second++;
                }
            } else if (chr == 'D') {
                if (!m.empty()) {
                    if (tmp == 1) {
                        auto it = m.end();
                        it--;
                        if (it->second > 1) {
                            it->second--;
                        } else {
                            m.erase(it);
                        }
                    } else if (tmp == -1) {
                        if (m.begin()->second > 1) {
                            m.begin()->second--;
                        } else {
                            m.erase(m.begin());
                        }
                    }
                }
            }
        }
        if (m.empty()) {
            cout << "EMPTY\n";
        } else {
            auto it = m.end();
            it--;
            cout << it->first << ' ' <<  m.begin()->first << '\n';
        }
    }
    return 0;
}