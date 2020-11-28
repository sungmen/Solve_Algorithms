#include <bits/stdc++.h>
using namespace std;
string solution(string p) {
    if (p.compare("") == 0) return "";
    int f = 0, s = 0, chk = 0;
    string u = "", v = "";
    for (auto &c : p) {
        if (c == '(') f++;
        else s++;
        if(!chk) u += c;
        else v += c;
        if (f==s) chk = 1;
    }
    string str = "";
    if (u[0] == '(') str = u + solution(v);
    else {
        string k = "";
        for (int i = 1; i < u.size()-1; i++) {
            if (u[i] == '(') k += ')';
            else k += '(';
        }
        str = '(' + solution(v) + ')' + k;
    }
    return str;
}