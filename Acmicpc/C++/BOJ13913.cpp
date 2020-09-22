#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
typedef pair<int, int> pi;
bool arr[MAX];
int t[MAX];
int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k; cin >> n >> k;
    queue<pi> q;
    q.push(make_pair(0, n));
    arr[n] = true;
    while(!q.empty()){
        pi pr = q.front();
        q.pop();
        if(pr.second == k) {    
            cout << pr.first << '\n';
            stack<int> s;
            int tmp = pr.second;
            s.push(tmp);
            while(tmp!=n) {
                tmp = t[tmp];
                s.push(tmp);
            }
            while(!s.empty()) {
                cout << s.top() << ' ';
                s.pop();
            }   
            return 0;
        }
        if(pr.second*2 < MAX && !arr[pr.second*2]) {
            q.push(make_pair(pr.first+1, pr.second*2));
            arr[pr.second*2] = true;
            t[pr.second*2] = pr.second;
        }
        if(pr.second+1 < MAX && !arr[pr.second+1]) {
            q.push(make_pair(pr.first+1, pr.second+1));
            arr[pr.second+1] = true;
            t[pr.second+1] = pr.second;
        }
        if(pr.second-1 >= 0 && !arr[pr.second-1]) {
            q.push(make_pair(pr.first+1, pr.second-1));
            arr[pr.second-1] = true;
            t[pr.second-1] = pr.second;
        }
    }
    return 0;
}