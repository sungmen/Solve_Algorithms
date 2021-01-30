#include <bits/stdc++.h>
using namespace std;
struct sol{
	int x;
	int y;
	int cnt;
};
const int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main() {
	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int r, c; cin >> r >> c;
	vector<vector<char>> v(r, vector<char>(c));
	queue<sol> q;
	int chk[2][r][c];
	memset(chk, false, sizeof(chk));
	pair<int, int> target;
	queue<pair<int, int>> water;
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < c; j++) {
			v[i][j] = str[j];
			if (v[i][j] == 'S') {
				chk[1][i][j] = true;
				q.push({i, j, 0});
			}
			if (v[i][j] == '*') {
				chk[0][i][j] = true;
				water.push({i, j});
			}
			if (v[i][j] == 'D') {
				target = {i, j};
			}
		}
	}
	while(1) {
		int waterSize = water.size();
		while (waterSize--) {
			pair<int, int> curWater = water.front();
			water.pop();
			for (int i = 0; i < 4; i++) {
				pair<int, int> next = {curWater.first + pos[i][0], curWater.second + pos[i][1]};
				if (next.first < 0 || next.first >= r || next.second < 0 || next.second >= c || chk[0][next.first][next.second] || v[next.first][next.second] == 'X' || v[next.first][next.second] == 'D') continue;
				chk[0][next.first][next.second] = true;
				water.push({next.first, next.second});
			}
		}
		int qSize = q.size();
		if (qSize == 0) {
			cout << "KAKTUS";
			return 0;
		}
		while(qSize--) {
			sol cur = q.front();
			q.pop();
			if (cur.x == target.first && cur.y == target.second) {
				cout << cur.cnt;
				return 0;
			}
			for (int i = 0; i < 4; i++) {
				pair<int, int> next = {cur.x + pos[i][0], cur.y + pos[i][1]};
				if (next.first < 0 || next.first >= r || next.second < 0 || next.second >= c || chk[0][next.first][next.second] || chk[1][next.first][next.second] || v[next.first][next.second] == 'X') continue;
				chk[1][next.first][next.second] = true;
				q.push({next.first, next.second, cur.cnt + 1});
			}
		}
	}
	return 0;
}
