#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
vector <int> v[MAX];

void fndRoot(int cur, int root, vector<int> &fnd) {
    fnd[cur] = root;
    for (int i = 0; i < v[cur].size(); i++) {
        if (v[cur][i] != root) {
            fndRoot(v[cur][i], cur, fnd);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0 ; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    
    vector<int> fnd(n+1);

    fndRoot(1, 0, fnd);

    for (int i = 2; i <= n; i++) {
        cout << fnd[i] << "\n";
    }

    return 0;
}