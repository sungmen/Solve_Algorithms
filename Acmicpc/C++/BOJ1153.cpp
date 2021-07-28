#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 1;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    bool prime[MAX];
    memset(prime, 1, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    map<int, int> primeM;
    for (int i = 2; i < MAX; i++) {
        if (prime[i]) {
            primeM[i] = 1;
            for (int j = i + i; j < MAX; j += i) {
                if (prime[j]) {
                    prime[j] = false;
                }
            }
        }
    }
    int n; cin >> n;
    for (auto it = primeM.begin(); it != primeM.end(); it++) {
        if (it->first >= n) break;
        for (auto it2 = primeM.begin(); it2 != primeM.end(); it2++) {
            if (it->first + it2->first >= n) break;
            for (auto it3 = primeM.begin(); it3 != primeM.end(); it3++) {
                if (it->first + it2->first + it3->first >= n) break;
                if (prime[n-it->first-it2->first-it3->first]) {
                    cout << it->first << ' ' << it2->first << ' ' << it3->first << ' ' << n - it->first - it2->first - it3->first;
                    return 0;
                }
            }
        }
    }
    cout << -1;
    return 0;
}