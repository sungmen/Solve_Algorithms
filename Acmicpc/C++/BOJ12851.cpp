#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
typedef pair<int, int> pi;
bool arr[MAX];
int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k; cin >> n >> k;
    queue<pi> q;
    q.push(make_pair(0, n));
    arr[n] = true;
    int min_v = 0;
    int cnt = 1;
    while(!q.empty()){
        pi pr = q.front();
        q.pop();
        arr[pr.second] = true;
        if(!min_v && pr.second == k) {
            min_v = pr.first;
        } else if(min_v && min_v == pr.first && pr.second == k) {
            cnt++;
        }
        if(pr.second*2 < MAX && !arr[pr.second*2]) {
            q.push(make_pair(pr.first+1, pr.second*2));
        }
        if(pr.second+1 < MAX && !arr[pr.second+1]) {
            q.push(make_pair(pr.first+1, pr.second+1));
        }
        if(pr.second-1 >= 0 && !arr[pr.second-1]) {
            q.push(make_pair(pr.first+1, pr.second-1));
        }
    }
    cout << min_v << "\n" << cnt;
    return 0;
}