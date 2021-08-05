#include <bits/stdc++.h>
using namespace std;
vector<string> split(string s, string del) {
    int start = 0, e = s.find(del);
    vector<string> vs;
    while (e != -1) {
        vs.push_back(s.substr(start, e - start));
        start = e + del.size();
        e = s.find(del, start);
    }
    vs.push_back(s.substr(start, e - start));
    return vs;
}
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        string p, m; 
        int n;
        cin >> p >> n >> m;
        deque<string> dq;
        if (m.compare("[]")) {
            m = m.substr(1, m.size() - 2);
            vector<string> vs = split(m, ",");
            for (auto vs_ : vs) dq.push_back(vs_);
        }
        bool chk = 0;
        bool err_chk = false;
        for (auto p_ : p) {
            if (p_ == 'R') {
                if (chk) chk = 0;
                else chk = 1;
            } else {
                if (dq.empty()) {
                    err_chk = 1;
                    break;
                } else {
                    if (!chk) {
                        dq.pop_front();
                    } else {
                        dq.pop_back();
                    }
                }
            }
        }
        if (err_chk) cout << "error" << '\n';
        else {
            cout << '[';
            if (!dq.empty()) {
                if (!chk) {
                    while(dq.size() != 1) {
                        cout << dq.front() << ',';
                        dq.pop_front();
                    }
                    cout << dq.front();
                } else {
                    while(dq.size() != 1) {
                        cout << dq.back() << ',';
                        dq.pop_back();
                    }
                    cout << dq.back();
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}