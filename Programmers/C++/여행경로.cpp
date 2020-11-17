#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> tickets_;
vector<string> answer;
int res_cnt;
void dfs(string tmp, int cnt, vector<bool>& chk, vector<string>& res) {
    res.emplace_back(tmp);
    if(res_cnt < cnt) {
        res_cnt = cnt;
        answer = res;
    }
    for (int i = 0; i < tickets_.size(); i++) {
        if (tmp == tickets_[i][0] && !chk[i]) {
            chk[i] = 1;
            dfs(tickets_[i][1], cnt+1, chk, res);
            chk[i] = 0;
        }
    }
    res.pop_back();
}
vector<string> solution(vector<vector<string>> tickets) {
    ios_base::sync_with_stdio(false);
    sort(tickets.begin(), tickets.end());
    tickets_ = tickets;
    int cnt = 0;
    vector<string> res;
    vector<bool> chk(tickets.size(), false);
    dfs("ICN", 0, chk, res);
    return answer;
}