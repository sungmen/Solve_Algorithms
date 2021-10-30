#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> vstk;
int sum (int l, int r) {
    while (l >= 0 && r < vstk.size()) {
        if (vstk[l].first == vstk[r].first && vstk[l].second + vstk[r].second >= 4) {
            l--;
            r++;
        } else {
            break;
        }
    }
    int tmp = 0;
    for (int j = l; j >= 0; --j) tmp += vstk[j].second;
    for (int j = r; j < vstk.size(); ++j) tmp += vstk[j].second;
    return tmp;
}
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0;  i < n; ++i) cin >> v[i];
    vstk.push_back({v[0], 1});
    for (int i = 1; i < n; ++i) {
        if (vstk.back().first == v[i]) {
            vstk.back().second++;
        } else {
            vstk.push_back({v[i], 1});
        }
    }
    int answer = n;
    for (int i = 1; i < vstk.size() - 1; ++i) {
        if (vstk[i].second == 1 && vstk[i-1].first == vstk[i+1].first && vstk[i-1].second + vstk[i].second + vstk[i+1].second >= 4) {
            answer = min(answer, sum(i-2, i+2));
        } else if (vstk[i-1].second >= 3) {
            if (vstk[i].second == 1) {
                answer = min(answer, sum(i-2, i+1));
            } else {
                answer = min(answer, sum(i-2, i));
            }
        } else if (vstk[i+1].second >= 3) {
            if (vstk[i].second == 1) {
                answer = min(answer, sum(i-1, i+2));
            } else {
                answer = min(answer, sum(i, i+2));
            }
        }
    }
    cout << answer;
    return 0;
}
