#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int c;
    for(cin>>c;c--;){
        int n, l;
        cin >> n >> l;
        vector<double> v(n+1);
        for(int i = 1; i <= n; i++) {
            cin >> v[i];
            v[i] += v[i-1];
        }
        double min = DBL_MAX;
        for(int i = 0; i <= n-l; i++) {
            for(int j = i+l; j <= n; j++) {
                double tmp = (v[j]-v[i])/(j-i);
                min = min > tmp ? tmp : min;
            }
        }
        cout<<fixed;
        cout.precision(11);
        cout << min << "\n";
    }
}