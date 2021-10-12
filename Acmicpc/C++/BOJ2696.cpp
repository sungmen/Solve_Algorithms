#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int m; cin >> m;
        priority_queue<int> pqMax, pqMin;
        vector<int> res;
        for (int i = 0; i < m; ++i) {
            int n; cin >> n;
            if (pqMax.empty()) pqMax.push(-n);
            else {
                if (-pqMax.top() <= n) {
                    pqMax.push(-n);
                } else {
                    pqMin.push(n);
                }
                if (pqMax.size() > pqMin.size() + 1) {
                    pqMin.push(-pqMax.top());
                    pqMax.pop();
                } else if (pqMin.size() > pqMax.size()) {
                    pqMax.push(-pqMin.top());
                    pqMin.pop();
                }
            }
            if (!(i % 2)) res.push_back(-pqMax.top());
        }
        cout << res.size() << '\n';
        for (int i = 0; i < res.size(); ++i) {
            if (i > 9 && !(i % 10)) cout << '\n';
            cout << res[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}