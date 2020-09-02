#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>>v(N);
    for(int i = 0; i < N ; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    vector<int> w(K);
    for(int i = 0; i < K; i++) {
        cin >> w[i];
    }
    sort(w.begin(), w.end());
    long long sum = 0;
    priority_queue<int> pq;
    for (int i = 0, j = 0; i < K; i++) {
        while(j < N && v[j].first <= w[i]) pq.push(v[j++].second);
        if(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum;
    return 0;
}