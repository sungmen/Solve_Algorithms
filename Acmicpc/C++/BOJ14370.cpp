#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    map<char, int> alp[10];
    string alpa[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    for (int i = 0; i < 10; i++) {
        for (char s : alpa[i]) {
            alp[i][s]++;
        }
    }
    for (int i = 1; i <= t; i++) {
        string str; cin >> str;
        string res = "";
        map<char, int> m;
        for (auto s : str) {
            m[s]++;
        }
        if (m['Z']) {
            int n = m['Z'];
            for (map<char, int>::iterator it = alp[0].begin(); it != alp[0].end(); it++) {
                m[it->first] -= (it->second * n);
            }
            string tmp(n, '0');
            res += tmp;
        }
        if (m['W']) {
            int n = m['W'];
            for (map<char, int>::iterator it = alp[2].begin(); it != alp[2].end(); it++) {
                m[it->first] -= (it->second * n);
            }
            string tmp(n, '2');
            res += tmp;
        }
        if (m['U']) {
            int n = m['U'];
            for (map<char, int>::iterator it = alp[4].begin(); it != alp[4].end(); it++) {
                m[it->first] -= (it->second * n);
            }
            string tmp(n, '4');
            res += tmp;
        }
        if (m['X']) {
            int n = m['X'];
            for (map<char, int>::iterator it = alp[6].begin(); it != alp[6].end(); it++) {
                m[it->first] -= (it->second * n);
            }
            string tmp(n, '6');
            res += tmp;
        }
        if (m['G']) {
            int n = m['G'];
            for (map<char, int>::iterator it = alp[8].begin(); it != alp[8].end(); it++) {
                m[it->first] -= (it->second * n);
            }
            string tmp(n, '8');
            res += tmp;
        }
        if (m['H']) {
            int n = m['H'];
            for (map<char, int>::iterator it = alp[3].begin(); it != alp[3].end(); it++) {
                m[it->first] -= (it->second * n);
            }
            string tmp(n, '3');
            res += tmp;
        }
        if (m['F']) {
            int n = m['F'];
            for (map<char, int>::iterator it = alp[5].begin(); it != alp[5].end(); it++) {
                m[it->first] -= (it->second * n);
            }
            string tmp(n, '5');
            res += tmp;
        }
        if (m['S']) {
            int n = m['S'];
            for (map<char, int>::iterator it = alp[7].begin(); it != alp[7].end(); it++) {
                m[it->first] -= (it->second * n);
            }
            string tmp(n, '7');
            res += tmp;
        }
        if (m['I']) {
            int n = m['I'];
            for (map<char, int>::iterator it = alp[9].begin(); it != alp[9].end(); it++) {
                m[it->first] -= (it->second * n);
            }
            string tmp(n, '9');
            res += tmp;
        }
        if (m['O']) {
            int n = m['O'];
            for (map<char, int>::iterator it = alp[1].begin(); it != alp[1].end(); it++) {
                m[it->first] -= (it->second * n);
            }
            string tmp(n, '1');
            res += tmp;
        }
        sort(res.begin(), res.end());
        cout << "Case #" << i << ": " << res << '\n';
    }

    return 0;
}