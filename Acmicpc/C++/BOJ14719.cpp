#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int h,w;cin>>h>>w;
    vector<int> vec(w);
    for (int i = 0; i < w; i++) cin >> vec[i];
    int ans = 0;
    for (int i = 1; i < w-1; i++) {
        int l = 0, r = 0;
        for (int j = 0; j < i; j++)  l = max(l, vec[j]);
        for (int j = w-1; j > i; j--) r = max(r, vec[j]);
        ans += (min(l, r)-vec[i] < 0 ? 0 : min(l, r)-vec[i]);
    }
    cout << ans << '\n';
    return 0;
}