#include <bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        return abs(a) > abs(b);
    }
};

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, cmp> pq;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        pq.push(c);
    }
    int min_v = INT_MAX;
    int before;
    if(!pq.empty()){
        before = pq.top();
        pq.pop();
    }

    int res1, res2;
    while(!pq.empty()) {
        int tmp = pq.top();
        pq.pop();
        if(tmp + before == 0) {
            if (tmp < before) {
                res1 = tmp;
                res2 = before;
            } else {
                res1 = before;
                res2 = tmp;
            }
            break;
        }
        if (abs(min_v) > abs(before + tmp)) {
            min_v = abs(before + tmp);
            if (tmp < before) {
                res1 = tmp;
                res2 = before;
            } else {
                res1 = before;
                res2 = tmp;
            }
        }
        before = tmp;
    }
    cout << res1 << ' ' << res2;
    return 0;
}