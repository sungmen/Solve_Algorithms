#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
typedef pair<int, int> pi;
bool arr[MAX];
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k; cin >> n >> k;
    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.push(make_pair(0, n));
    arr[n] = true;
    while(!q.empty()){
        pi pr = q.top();
        q.pop();
        if(pr.second == k) {
            cout << pr.first;
            return 0;
        }
        if(pr.second*2 < MAX && !arr[pr.second*2]) {
            q.push(make_pair(pr.first, pr.second*2));
            arr[pr.second*2] = true;
        }
        if(pr.second+1 < MAX && !arr[pr.second+1]) {
            q.push(make_pair(pr.first+1, pr.second+1));
            arr[pr.second+1] = true;
        }
        if(pr.second-1 >= 0 && !arr[pr.second-1]) {
            q.push(make_pair(pr.first+1, pr.second-1));
            arr[pr.second-1] = true;
        }
    }
    return 0;
}