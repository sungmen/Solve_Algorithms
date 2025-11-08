#include <bits/stdc++.h>
using namespace std;
char arr[10201];
int t,n,m,cnt;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    for(cin>>t;t--;){
        cin>>n>>m;
        for(int i=0;i<n*m;i++)cin>>arr[i];
        cnt=0;
        for(int i=(n-1)*m;i<n*m;i++)if(arr[i]=='D')cnt++;
        for(int i=(m-1);i<n*m;i+=m)if(arr[i]=='R')cnt++;
        cout << cnt << '\n';
    }
}