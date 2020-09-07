#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    for(cin>>t;t--;) {
        int n; cin >> n;
        int arr[101];
        for(int i = 0; i < n; i++) cin >> arr[i];
        for(int i = n - 1; i >= 0; i--) cout << arr[i] << ' ';
        cout << '\n';
    }
    return 0;
}