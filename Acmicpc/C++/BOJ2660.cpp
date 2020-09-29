#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int d[50][50];
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) d[i][j] = INF;
    for (int i = 0; i < n; i++) d[i][i] = 0;
    while(1) {
        int a, b; cin >> a >> b;
        if(a == -1) break;
        d[a-1][b-1] = 1;
        d[b-1][a-1] = 1;
    }
    int res[50];
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            cnt =  max(cnt, d[i][j]);
        }
        res[i] = cnt;
    }
    int mm = INT_MAX;
    for (int i = 0; i < n; i++) {
        mm = min(mm, res[i]);
    }
    int count = 0;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        if (mm == res[i]) {
            count++;
            v.emplace_back(i+1);
        }
    }
    cout << mm << ' ' << count << '\n';
    for (auto i : v) cout << i << ' ';
    return 0;
}