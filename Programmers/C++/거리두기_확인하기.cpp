#include <bits/stdc++.h>
using namespace std;
const int POS[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}, {1, 1},  {-1, 1}, {-1, -1}};
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int k = 0; k < places.size(); k++) {
        queue<pair<int, int>> q;
        for (int i = 0; i < places[k].size(); i++) {
            for (int j = 0; j < places[k][i].size(); j++) {
                if (places[k][i][j] == 'P') q.push({i, j});
            }
        }
        int m = places[k].size();
        int n = places[k][0].size();
        bool chk = true;
        while (!q.empty()) {
            pair<int, int> pii = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                pair<int, int> next = {pii.first + POS[i][0], pii.second + POS[i][1]};
                if (next.first < 0 || next.first >= m || next.second < 0 || next.second >= n || places[k][next.first][next.second] == 'X') continue;
                if (places[k][next.first][next.second] == 'P') {
                    chk = false;
                    break;
                }
                next = {next.first + POS[i][0], next.second + POS[i][1]};
                if (next.first < 0 || next.first >= m || next.second < 0 || next.second >= n || places[k][next.first][next.second] == 'X') continue;
                if (places[k][next.first][next.second] == 'P') {
                    chk = false;
                    break;
                }
            }
            if (!chk) break;
            for (int i = 4; i < 8; i++) {
                pair<int, int> next = {pii.first + POS[i][0], pii.second + POS[i][1]};
                if(next.first < 0 || next. first >= m || next.second < 0 || next.second >= n || places[k][next.first][next.second] != 'P') continue;
                pair<int, int> y = {pii.first + POS[i][0], pii.second};
                pair<int, int> x = {pii.first, pii.second + POS[i][1]};
                if (places[k][y.first][y.second] == 'O' || places[k][x.first][x.second] == 'O') {
                    chk = false;
                    break;
                }
            }
            if (!chk) break;
        }
        answer.push_back((chk?1:0));
    }
    return answer;
}