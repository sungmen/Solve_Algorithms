#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int c;
    cin >> c;
    vector<int> v(c);
    for(int i = 0; i < c; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int sum = 0;
    for (int i = 0; i < c-2;i++) {
        for (int j = i+1; j < c - 1; j++) {
            for (int z = j + 1; z < c; z++) {
                if(v[i]!=v[j] && v[j] != v[z] && v[i] + v[j] > v[z]) {
                    sum++;
                }
            }
        }
    }
    cout << sum;
    return 0;
}