#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    vector<int> res;
    int i = 0;
    while(i < n) {
        if (v[i] <= 0) {
            if (i+1 < n && (v[i+1] < 0 || v[i+1] == 0)) {
                res.push_back(v[i]*v[i+1]);
                i+=2;
                continue;
            }
            res.push_back(v[i]);
            i++;
        } else if (v[i] > 0) {
            break;
        }
    }
    int j = n-1;
    while (j >= i) {
        if (v[j] == 1) {
            res.push_back(v[j]);
            j--;
        } else if (j - 1 >= i) {
            if (v[j-1] == 1) {
                res.push_back(v[j]);
                j--;
            } else {
                res.push_back(v[j] * v[j-1]);
                j-=2;
            }
        } else {
            res.push_back(v[j]);
            j--;
        }
    }
    cout << accumulate(res.begin(), res.end(), 0);
    return 0;
}