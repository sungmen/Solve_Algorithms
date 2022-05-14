#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, q; cin >> n >> q;
    map<int, int> x_, x_2;
    map<int, int> y_, y_2;
    for (int i = 1; i <= 200001; i++) {
        x_2[i] = 1;
        y_2[i] = 1;
    }
    while(q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, y; cin >> x >> y;
            x_[x]++;
            y_[y]++;
            if (x_2.find(x) != x_2.end())
                x_2.erase(x);
            if (y_2.find(y) != y_2.end())
                y_2.erase(y);
        } else if (t == 2) {
            int x, y; cin >> x >> y;
            x_[x]--;
            if (x_[x] == 0) {
                x_.erase(x);
                x_2[x] = 1;
            }
            y_[y]--;
            if (y_[y] == 0) {
                y_.erase(y);
                y_2[y] = 1;
            }
        } else if (t == 3) {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2; 
            auto itlow = x_2.lower_bound(x1);           
            if (!(itlow->first >= x1 && itlow->first <= x2)) {
                cout << "Yes\n";
                continue;
            }
            itlow = y_2.lower_bound(y1);
            if (!(itlow->first >= y1 && itlow->first <= y2)) {
                cout << "Yes\n";
                continue;
            }
            cout << "No\n";
        }
    }
    return 0;
}
