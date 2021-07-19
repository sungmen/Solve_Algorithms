#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    set<int> s;
    int cnt = 0;
    bool chk = true;
    while(1) {
        int a, b; cin >> a >> b;
        if (!a && !b) {
            if (cnt != 0 && s.size() != cnt + 1) {
                chk = false;
            }
            cout << "Case " << t << " is " << (chk ? "" : "not ") << "a tree.\n";
            s.clear();
            ++t;
            cnt = 0;
            chk = true;
            continue;
        } else if (a < 0 && b < 0) {
            return 0;
        }
        s.insert(a);
        s.insert(b);
        cnt++;
    }
    return 0;
}