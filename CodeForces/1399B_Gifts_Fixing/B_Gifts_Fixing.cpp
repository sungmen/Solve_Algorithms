#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t;
    for(cin>>t;t--;){
        int n;
        cin >> n;
        vector<int> v1(n);
        vector<int> v2(n);
        int min1 = INT_MAX;
        for (int i = 0; i < n; i++) {
            cin >> v1[i];
            if(min1 > v1[i]) {
                min1 = v1[i];
            }
        }
        int min2 = INT_MAX;
        for (int i = 0; i < n; i++) {
            cin >> v2[i];
            if(min2 > v2[i]) {
                min2 = v2[i];
            }
        }
        ll cnt = 0;
        for (int i = 0 ; i< n; i++) {
            v1[i] -= min1;
            v2[i] -= min2;
            cnt += max(v1[i], v2[i]);
        }
        cout << cnt << "\n";
    }
    return 0;
}