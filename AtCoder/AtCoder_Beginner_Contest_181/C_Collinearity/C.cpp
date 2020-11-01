#include <bits/stdc++.h>
using namespace std;
int main() {
//     freopen("inputf.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v[i] = make_pair(a, b);
    }
    for(int i = 0; i < n; i++) {
        for  (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                if ((v[i].first-v[j].first) * (v[i].second - v[k].second) == (v[i].first - v[k].first) * (v[i].second - v[j].second)) {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }
    cout << "No";
    return 0;
}