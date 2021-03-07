#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_case; cin >> test_case;
    for (int t = 1; t <= test_case; ++t) {
    	long double d, n;
        long double l;
        cin >> d >> l >> n;
        // D(1+nㆍL%)
        long double sum = 0;
        long double p = l/100;
        for (int i = 0; i < n; i++) {
        	sum += d * (1 + (i * p));
        }
        cout << "#" << t << " " << (long)sum << "\n";
    }
    return 0;
}