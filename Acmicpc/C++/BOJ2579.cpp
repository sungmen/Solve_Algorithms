#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;   // count
    vector<int> v(n);   // stair
    vector<int> d(n);   // dp
    for(int i = 0; i < n; i++)
        cin >> v[i];
    d[0] = v[0];
    d[1] = max(v[0] + v[1], v[1]);
    d[2] = max(v[0] + v[2], v[1] + v[2]);

    for (int i = 3; i < n; i++) {
        d[i] = max(d[i-2] + v[i], v[i-1] + v[i] + d[i-3]);
    }
    
    cout << d[n-1];
}