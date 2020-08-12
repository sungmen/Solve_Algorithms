/*
*   https://www.acmicpc.net/problem/2252
*   줄세우기
*   위상 정렬 문제
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 32001

int n, node[MAX];
vector<int> v[MAX];

void bfs() {
    int res[MAX];
    queue<int> q;
    for (int _ = 1; _ <= n; _++) {
        if (node[_] == 0) {
            q.push(_);
        }
    }
    for (int _ = 1; _ <= n; _++) {
        if (q.empty()) return;
        int front = q.front();
        q.pop();
        res[_] = front;
        for (int _ = 0; _ < v[front].size(); _++) {
            int ins = v[front][_];
            if (--node[ins] == 0) {
                q.push(ins);
            }
        }
    }
    for (int _ = 1; _ <= n; _++) {
        cout << res[_] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    int M;
    for(cin>>M; M--;) {
        int a, b;
        cin >> a >> b;
        v[a].emplace_back(b);
        node[b]++;
    }
    bfs();
}