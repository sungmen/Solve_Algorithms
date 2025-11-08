#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    for(cin>>t;t--;){
        long long a, b, c;
        cin >> a >> b >> c;
        cout << max(a,max(b,c)) << '\n';
    }
    return 0;
}