#include <bits/stdc++.h>
using namespace std;
int main() {
	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		int q, d; cin >> q >> d;
		for (int i = 0; i < q; i++) {
			int a; cin >> a;
			int tmp = a;
			bool chk = false;
			while (tmp > 0) {
				if (tmp % 10 == d) {
					chk = true;
					break;
				}
				tmp /= 10;
			}
			if (!tmp) {
				while (a > 0) {
					if ((a%10) == d || (a > 9 && ((a/10)%10)==d)) {
						tmp = true;
						break;
					}
					a -= d;
				}
			}
			if (!tmp) cout << "NO\n";
			else cout << "YES\n";
		}
	}
	return 0;
}
