#include <bits/stdc++.h>
using namespace std;
int main() {
	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	string str;cin >>str;
	if (str[0]== str[1] && str[1]==str[2]) cout << "Won";
	else cout << "Lost";
	return 0;
}
