#include <bits/stdc++.h>
using namespace std;
int arr[3][101];
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    for(cin>>t;t--;){
        int n; cin >> n;
        for(int j = 0; j < 3; j++) for(int i = 0; i < n; i++) cin >> arr[j][i];
        int p[n];
        p[0] = arr[0][0];
        int cnt = 0;
        for(int i = 1; i < n; i++) {
            if (i == n-1) {
                while(p[i-1] == arr[cnt][i] || p[0] == arr[cnt][i]) {
                    cnt++;
                }
            }
            else {
                while(p[i-1] == arr[cnt][i]) {
                    cnt++;
                }
            }
            p[i] = arr[cnt][i];
            cnt = 0;
        }

        for(int i = 0; i < n; i++) {
            cout << p[i] << ' ';
        }
        cout << '\n';
    }
}