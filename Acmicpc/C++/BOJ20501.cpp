#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.in", "r", stdin);
    int n; scanf("%d", &n);
    vector<bitset<2001>> b(n);
    for (int i = 0; i < n; ++i) {
        char tmp[2001];
        scanf("%s", &tmp);
        string str = tmp;
        for (int j{}; j < str.size() && j < n; ++j) {
            b[i][j] = (str[j] == '1') ? 1 : 0;
        }
    }
    int q; scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int a1, a2; scanf("%d %d", &a1, &a2);
        printf("%d\n", (b[a1-1]&b[a2-1]).count());
    }
    return 0;
}