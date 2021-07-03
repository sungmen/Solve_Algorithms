#include<bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	for(int test_case = 1; test_case <= 10; ++test_case) {
		int tmp; cin >> tmp;
        string str[16];
        pair<int, int> start, goal;
        for (int i = 0; i < 16; i++) {
         	cin >> str[i];
            for (int j = 0; j < 16; j++) {
            	if (str[i][j] == '2') start = {i, j};
                if (str[i][j] == '3') goal = {i, j};
            }
        }
        queue<pair<int, int>> q;
        q.push(start);
        int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> visit(16, vector<bool>(16, false));
        visit[start.first][start.second] = true;
        bool chk = false;
        while (! q.empty()) {
        	pair<int, int> cur = q.front();
            if (cur.first == goal.first && cur.second == goal.second) {
                chk = true;
            	break;
            }
            q.pop();
            for (int i = 0; i < 4; i++) {
                pair<int, int> next = {cur.first + pos[i][0], cur.second + pos[i][1]};
            	if (next.first >= 0 && next.first < 16 && next.second >= 0 && next.second < 16 && !visit[next.first][next.second] && str[next.first][next.second] != '1') {
                    visit[next.first][next.second] = true;
                    q.push(next);
                }
            }
        }
        cout << '#' << tmp << ' ' << (chk?'1':'0') << '\n';
	}
	return 0;
}