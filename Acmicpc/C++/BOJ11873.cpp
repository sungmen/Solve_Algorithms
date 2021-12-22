#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    while(1) {
        int n, m; cin >> n >> m;
        if (!n && !m) {
            return 0;
        }
        vector<int> v(m + 1, 0);
        v[0] = -1;
        int answer = 0;
        stack<int> stk;
        stk.push(0);
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int num; cin >> num;
                if (num) {
                    v[j] += 1;
                } else {
                    v[j] = 0;
                }
                int len = 0;
                while (!stk.empty() && v[stk.top()] >= v[j]) {
                    int p = stk.top();
                    stk.pop();
                    len += p - stk.top();
                    answer = max(answer, v[p] * len);
                }
                stk.push(j);
            }
            int len = 0;
            while (stk.size() > 1) {
                int p = stk.top();
                stk.pop();
                len += p - stk.top();
                answer = max(answer, v[p] * len);
            }
        }
        cout << answer << '\n';
    }
    return 0;
}
