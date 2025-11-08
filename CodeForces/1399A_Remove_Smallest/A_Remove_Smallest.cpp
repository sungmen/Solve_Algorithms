#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t;
    for(cin>>t;t--;){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int cnt = 0;
        if(n > 1) {
            for(int i = 1; i < n; i++) {
                if(abs(v[i-1]-v[i])>1)
                cnt = 1;
                if(cnt==1) {
                    break;
                }
            }
        }

                if(cnt >= 1) {
                    cout << "NO" << "\n";
                }
                else {
                    cout << "YES" << "\n";
                }
    }
    return 0;
}