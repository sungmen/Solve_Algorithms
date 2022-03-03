#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    priority_queue<long long> pq;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        pq.push(-num);
    }
    long long answer = 0;
    while (pq.size() != 1) {
        long long n1 = -pq.top();
        pq.pop();
        long long n2 = -pq.top();
        pq.pop();
        answer += (n1 + n2);
        pq.push(-(n1 + n2));
    }
    cout << answer;
    return 0;
}
