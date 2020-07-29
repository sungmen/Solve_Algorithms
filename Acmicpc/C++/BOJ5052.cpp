#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
#define MAX  10001

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int chk = 1;
        vector<string> v(n);
        for(int i = 0 ; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        for(int i = 0 ; i < n-1; i++) {
            string temp = v[i+1].substr(0,v[i].length());
            if(temp == v[i]) {
                chk = 0;
                break;
            }
        }
        if (chk) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}