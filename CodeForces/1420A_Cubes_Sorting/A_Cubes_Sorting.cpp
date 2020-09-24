#include <bits/stdc++.h>
using namespace std;
const int MAX = 5*1e4;
int arr[MAX];
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        int cnt = 0;
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 0; i < n-1; i++) {
            if(arr[i] <= arr[i+1]) {
                cnt++;
                break;
            }
        }
        if(cnt) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}