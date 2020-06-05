#include <iostream>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<int> stk;
    for (int i = 0; i < s.size(); i++) {
        if(!stk.empty() && stk.top() == s[i])
            stk.pop();
        else
            stk.push(s[i]);
    }
    
    return stk.empty() ? 1:0;
}