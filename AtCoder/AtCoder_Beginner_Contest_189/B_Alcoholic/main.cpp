#include <bits/stdc++.h>
using namespace std;
int main() {
	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	long long n;
	long long x;
	cin >> n >> x;
	x *= 100;
	for (int i = 0 ; i < n ; i++) {
		long long  v;
		long long p; 
		cin >> v >> p;
		long long  res = v * p;
		x -= res;
		if (x < 0) {
			cout << i+1;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
