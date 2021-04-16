#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = 0;
    int si = s.size();
    while(si--) {
        string str = s;
        stack<char> stk;
        for (auto i : str) {
            if (i == '[' || i == '{' || i == '(') {
                stk.push(i);
            } else if (i == ']' && !stk.empty() && stk.top() == '[') {
                stk.pop();
            } else if (i == '}' && !stk.empty() && stk.top() == '{') {
                stk.pop();
            } else if (i == ')' && !stk.empty() && stk.top() == '(') {
                stk.pop();
            } else {
                stk.push(i);
            }
        }
        if (stk.empty()) {
            answer++;
        }
        
        char tmp = s.front();
        s += tmp;
        s.erase(0,1);
    }
    return answer;
}