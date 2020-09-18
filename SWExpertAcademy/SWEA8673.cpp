#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;cin>>t;
    for (int te=1;te<=t;te++){
        ll res = 0;
        int n; cin >> n;
        int vn = 1 << n;
        vector<int> v(vn);
        for(int i = 0; i < vn; i++) {
            cin >> v[i];
        }
        while(vn > 1) {
            int j = 0;
            for(int i = 0; i < vn; i++){
            }
            for (int i = 0; i < vn; i+=2) {
                res += abs(v[i]-v[i+1]);
                v[j] = max(v[i], v[i+1]);
                j++;
            }
            vn /= 2;
        }
        cout << '#'<<te<< ' '<< res <<'\n';
    }
}