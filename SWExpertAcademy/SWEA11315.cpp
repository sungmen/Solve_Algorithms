// https://swexpertacademy.com/ 
// 11315. 오목 판정
#include <bits/stdc++.h>
using namespace std;
int main() {
	// freopen("sample_input.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t; cin >> t;
	for (int test_c = 1; test_c <= t; test_c++) {
		int n; cin>>n;
		char chr[n][n];
		for (int i = 0; i < n; i++) {
			string str; cin >> str;
			for (int j = 0; j < n; j++) {
				chr[i][j] = str[j];
			}
		}
		bool chk = false;
		for (int i = 0; i <= n - 5; i++) {
			for (int j = 0; j < n; j++) {
				if (chr[i][j] == 'o' && chr[i][j] == chr[i+1][j] && chr[i+1][j] == chr[i+2][j] && chr[i+2][j] == chr[i+3][j] && chr[i+3][j] == chr[i+4][j]) {
					chk = true;
					break;
				}
				if (chr[j][i] == 'o' && chr[j][i] == chr[j][i+1] && chr[j][i+1] == chr[j][i+2] && chr[j][i+2] == chr[j][i+3] && chr[j][i+3] == chr[j][i+4]) {
					chk = true;
					break;
				}
			}
			if(chk) break;
		}
		if(!chk) {
			for (int i = 0; i <= n - 5; i++) {
				for (int j = 0; j <= n - 5; j++) {
					if (chr[i][j] == 'o' && chr[i][j] == chr[i+1][j+1] && chr[i+1][j+1] == chr[i+2][j+2] && chr[i+2][j+2] == chr[i+3][j+3] && chr[i+3][j+3] == chr[i+4][j+4]) {
						chk = true;
						break;
					}
				}
				if(chk) break;
			}
		}
		if(!chk) {
			for (int i = 0; i <= n - 5; i++) {
				for (int j = n-1; j >= 4; j--) {
					if (chr[i][j] == 'o' && chr[i][j] == chr[i+1][j-1] && chr[i+1][j-1] == chr[i+2][j-2] && chr[i+2][j-2] == chr[i+3][j-3] && chr[i+3][j-3] == chr[i+4][j-4]) {
						chk = true;
						break;
					}
				}
				if(chk) break;
			}
		}
		if(chk) {
			cout << '#' << test_c << " YES\n";
		} else {
			cout << '#' << test_c << " NO\n";
		}
	}
	return 0;
}
