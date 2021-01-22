#include <bits/stdc++.h>
using namespace std;
int main() {
	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	int d[s1.size()+1][s2.size()+1][s3.size()+1];
	memset(d, 0, sizeof(d));
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			for (int k = 0; k < s3.size(); k++) {
				if (s1[i]==s2[j] && s2[j] == s3[k]) {
					d[i+1][j+1][k+1] = d[i][j][k] + 1;
				} else {
					d[i+1][j+1][k+1] = max(d[i+1][j+1][k], max(d[i+1][j][k+1], d[i][j+1][k+1]));
				}
			}
		}
	}
	cout << d[s1.size()][s2.size()][s3.size()];
	return 0;
}
