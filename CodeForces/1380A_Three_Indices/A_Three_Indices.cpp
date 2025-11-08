#include <iostream>
using namespace std;
int a[1002];
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for (int i = 1 ; i <= n; i++) {
            cin >> a[i];
        }
        
        int idx = 0;
        for (int i = 2; i < n; i++) {
            if (a[i] > a[i-1] && a[i] > a[i+1]) {
                idx = i;
            }
        }
        if (idx > 0) {
            cout << "YES\n" << idx-1 << " " << idx << " " << idx+1 << "\n";
        } else {
            cout << "NO" << "\n";
        }
        
    }
        
    return 0;
}