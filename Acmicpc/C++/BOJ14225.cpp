#include <bits/stdc++.h>
using namespace std;
const int MAX = 2 * 1e6 + 1;
int arr[MAX];
int main() {
    // freopen("input.txt", "r", stdin);
    int n; cin>>n;
    queue<int> q;
    for(int i = 0; i < n; i++) {
        int t; 
        cin >> t;
        q.push(t);
    }
    vector<int> v;
    v.emplace_back(0);
    while(!q.empty()) {
        int k = q.front();
        q.pop();
        int v_s = v.size();
        for(int i = 0; i < v_s; i++){
            v.emplace_back(v[i]+k);
            arr[v[i]+k] = 1;
        }
    }
    for (int i = 1; i < MAX; i++) {
        if(!arr[i]) {
            cout << i;
            return 0;
        }
    }
    return 0;
}