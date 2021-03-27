#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e3+1;
int poe[MAX];
struct position {
    int x, y, r;
};
void union_set() {
    for (int i = 0; i < MAX; i++) {
        poe[i] = i;
    }
}
int find_pos(int a) {
    if (poe[a] == a) return a;
    else {
        int tmp = find_pos(poe[a]);
        poe[a] = tmp;
        return tmp;
    }
}
void merge_set(int a, int b) {
    int merge_a = find_pos(a);
    int merge_b = find_pos(b);
    if (merge_a == merge_b) return;
    else {
        poe[merge_a] = merge_b;
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        union_set();
        int n; cin >> n;
        vector<position> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].x >> v[i].y >> v[i].r;
        }
        int answer = n;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                position first = v[i];
                position second = v[j];
                long long dis = (long long)pow((first.r + second.r),2.0);
                long long dis2 = (long long)pow((first.x - second.x), 2.0) + (long long)pow((first.y - second.y), 2.0);
                if (dis >= dis2 && find_pos(i) != find_pos(j)) {
                    merge_set(i, j);
                    --answer;
                }
            }   
        }
        cout << answer << '\n';
    }    
    return 0;
}