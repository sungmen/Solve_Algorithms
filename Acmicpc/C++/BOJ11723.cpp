#include <bits/stdc++.h>
using namespace std;
int arr[21];
void sets(string str) {
    switch(str[0]) {
    case 'a':
        for(int i = 1; i < 21; i++) if(!arr[i]) arr[i] = 1;
        break;        
    case 'e':
        for (int i = 1; i < 21; i++) if(arr[i]) arr[i] = 0;
        break;
    }
}
void sets(string str, int n) {
    switch(str[0]) {
    case 'a':
        if(!arr[n]) arr[n] = 1;
        break;
    case 'r':
        if(arr[n]) arr[n] = 0;
        break;
    case 'c':
        cout << (arr[n] ? 1 : 0) << '\n';
        break;
    case 't':
        arr[n] = arr[n]^1;
        break;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    for(cin>>t;t--;) {
        string str;
        cin >> str;
        if((str[0] == 'a' && str[1] == 'l') || str[0] == 'e') sets(str);
        else {
            int n;cin >> n;
            sets(str, n);
        }
    }
    return 0;
}