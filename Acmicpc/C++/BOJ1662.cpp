#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string str; cin >> str;
    stack<pair<long long, long long>> stk;
    string tmp = "";
    int i = 0;
    while (i < str.size()) {
        if (str[i] == '(') {
            ++i;
            if (tmp.size()) stk.push({tmp.size(), tmp.back() - '0'});
            tmp = "";
            if (str[i] == ')') {
                i++;
                pair<int, int> s1;
                if (!stk.empty()) {
                    s1 = stk.top();
                    stk.pop();
                }
                s1.first--;
                stk.push(s1);
                while(i < str.size()) {
                    if (str[i] != '(' && str[i] != ')') {
                        tmp += str[i++];
                    } else {
                        break;
                    }
                }
                if (tmp.size() && !stk.empty()) {
                    pair<int, int> s4 = stk.top();
                    stk.pop();
                    stk.push({s4.first + tmp.size(), tmp.back() - '0'});
                }
            }
            tmp = "";
        } else if (str[i] == ')') {
            ++i;
            if (tmp.size()) stk.push({tmp.size(), tmp.back() - '0'});
            tmp = "";
            pair<long long, long long> s1, s2;
            if (!stk.empty()) {
                s1 = stk.top();
                stk.pop();
            }
            if (!stk.empty()) {
                s2 = stk.top();
                stk.pop();
            }
            --s2.first;
            while(i < str.size()) {
                if (str[i] != '(' && str[i] != ')') {
                    tmp += str[i];
                    i++;
                } else {
                    break;
                }
            }
            if (!tmp.size()) {
                stk.push({s2.first + s2.second * s1.first, s1.second});
            } else {
                stk.push({s2.first + s2.second * s1.first + tmp.size(), tmp.back() - '0'});                
            }
            tmp = "";
        } else {
            tmp += str[i];
            ++i;
        }
    }
    if (tmp.size()) {
        cout << tmp.size();
        return 0;
    }
    cout << (stk.top().first != -1 ? stk.top().first : 0) << '\n';
    return 0;
}