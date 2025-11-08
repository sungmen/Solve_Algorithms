#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t;cin>>t;
	while(t--) {
		int n; cin >> n;
		int b; cin >> b;
		int cnt = 1;
		int MAX = 1;
		for (int i = 1; i < n; i++) {
			int tmp; cin >> tmp;
			if (b==tmp) {
				cnt++;
				b=tmp;
			} else {
				if (MAX < cnt) MAX = cnt;
				cnt = 1;
				b=tmp;
			}
			if (MAX < cnt) MAX = cnt;
		}
		cout << MAX << '\n';
	}
	return 0;
}
