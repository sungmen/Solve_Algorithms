#include <bits/stdc++.h>
using namespace std;
vector<int> answer;
vector<vector<int>> arr_;
void dfs (int x, int y, int s) {
    bitset<2> b;
    b.set();
    for (int i = x; i < x+s; i++) {
        for (int j = y; j < y+s; j++) {
            if (arr_[i][j]) b[0] = 0;
            else b[1] = 0;
            if(!b[0] && !b[1]) {
                s /= 2;
                dfs(x, y, s);
                dfs(x, y+s, s);
                dfs(x+s, y, s);
                dfs(x+s, y+s, s);
                return;
            }
        }
    }
    if(b[0]) {
        answer[0]++;
        return;
    }
    if (b[1]) {
        answer[1]++;
        return;
    }
}
vector<int> solution(vector<vector<int>> arr) {
    ios_base::sync_with_stdio(false);
    answer.emplace_back(0);answer.emplace_back(0);
    arr_ = arr;
    dfs(0, 0, arr.size());
    return answer;
}