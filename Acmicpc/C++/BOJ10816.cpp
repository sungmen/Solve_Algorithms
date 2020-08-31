#include <bits/stdc++.h>
using namespace std;
int arr[20000001];
int main() {
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int n, m; cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr[num+10000000]++;
    }
    cin >> m;
    for (int i= 0; i < m; i++) {
        int num;
        cin >> num;
        cout << arr[num+10000000] << ' ';
    }
    return 0;
}