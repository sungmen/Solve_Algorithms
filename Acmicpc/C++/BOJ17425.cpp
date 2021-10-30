#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 1;
long long g[MAX], f[MAX];

void msum() {
    for (int i = 2; i < MAX; ++i) {
        for (int j = 1; j * i < MAX; ++j) {
            f[i * j] += i;
        }
    }
    for (int i = 1; i < MAX; ++i) {
        g[i] = g[i - 1] + f[i];
    }
}

int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    for (int i = 0; i < MAX; ++i) f[i] = 1;
    memset(g, 0, sizeof(g));
    msum();
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << g[n] << '\n';
    }
    return 0;
}