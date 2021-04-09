#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5+1;
int arr[MAX];
int cntSum[MAX];
void init_set() {
    for (int i = 0; i < MAX; i++) {
        arr[i] = i;
        cntSum[i] = 1;
    }
}
int find_union(int a) {
    if (a == arr[a]) return a;
    else return arr[a] = find_union(arr[a]);
}
int merge_union(int a, int b) {
    int fnd_a = find_union(a);
    int fnd_b = find_union(b);
    if (fnd_a == fnd_b) return max(cntSum[fnd_a], cntSum[fnd_b]);
    else {
        if (cntSum[fnd_a] < cntSum[fnd_b]) swap(fnd_a, fnd_b);
        arr[fnd_b] = fnd_a;
        cntSum[fnd_a] += cntSum[fnd_b];
        return cntSum[fnd_a];
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_case; cin >> test_case;
    while(test_case--) {
        init_set();
        map<string, int> m;
        int idx = 1;
        int f; cin >> f;
        while(f--) {
            string a, b; cin >> a >> b;
            if (!m[a]) m[a] = idx++;
            if (!m[b]) m[b] = idx++;
            cout << merge_union(m[a], m[b]) << '\n';
        }
    }
    return 0;
}