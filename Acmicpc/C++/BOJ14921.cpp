#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = n-1, MIN = a[l] + a[r];
    while(l < r) {
        int curr_sum = a[l] + a[r];
        if (abs(MIN) > abs(curr_sum)) {
            MIN = curr_sum;
        }
        if (curr_sum > 0) {
            r--;
        } else if (curr_sum < 0) {
            l++;
        } else if (curr_sum == 0) {
            cout << 0;
            return 0;
        }
    }
    cout << MIN;
    return 0;
}