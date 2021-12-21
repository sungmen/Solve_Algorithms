#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    while (1) {
        int t; cin >> t;
        if (!t) return 0;
        stack<pair<long long, long long>> stk;
        stk.push({-1, 0});
        long long answer = 0;
        for (int i = 1; i <= t; i++) {
            int h; cin >> h;
            long long length = 0;
            while (!stk.empty() && stk.top().first >= h) {
                pair<long long, long long> p = stk.top();
                stk.pop();
                length += p.second - stk.top().second;
                answer = max(answer, length * p.first);
            }
            stk.push({h, i});
        }
        long long length = 0;
        while (!stk.empty() && stk.size() > 1) {
            pair<long long, long long> p = stk.top();
            stk.pop();
            length += p.second - stk.top().second;
            answer = max(answer, length * p.first);
        }
        cout << answer << '\n';
    }
    return 0;
}