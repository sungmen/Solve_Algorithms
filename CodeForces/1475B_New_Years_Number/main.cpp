#include <bits/stdc++.h>
using namespace std;
int main() {
	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t;
	for (cin >> t; t--;) {
		int n; cin >> n;
		cout << ((n%2020)<=(n/2020)?"YES":"NO") << '\n';
	}
	return 0;
}
