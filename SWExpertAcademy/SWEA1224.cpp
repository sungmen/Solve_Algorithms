#include <iostream>
#include <stack>

using namespace std;

int main() {
	for (int test_case = 1; test_case <= 10; test_case++) {
        string str, res;
        int str_len;
        cin >> str_len;
        cin >> str;
        stack<char> stk;
        for (int i = 0; i < str.length(); i++) {
            switch(str[i]) {
                case '(':
                    stk.push(str[i]);
                    break;
                case ')':
                    while(!stk.empty() && stk.top() != '(') {
                        res += stk.top();
                        stk.pop();
                    }
                    stk.pop();
                    break;
                case '+':
                    while(!stk.empty() && stk.top() != '(') {
                        res += stk.top();
                        stk.pop();
                    }
                    stk.push(str[i]);
                    break;
                case '*':
                    while(!stk.empty() && stk.top() == '*') {
                        res += stk.top();
                        stk.pop();
                    }
                    stk.push(str[i]);
                    break;
                default:
                    res += str[i];
                    break;
            }
        }
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        
        stack<int> stk2;
		int n1, n2;
        for(int i = 0; i < res.length(); i++) {
         	switch(res[i]) {
                case '+':
                    n1 = stk2.top(); stk2.pop();
                    n2 = stk2.top(); stk2.pop();
                    stk2.push(n2 + n1);
                    break;
                case '*':
                    n1 = stk2.top(); stk2.pop();
                    n2 = stk2.top(); stk2.pop();
                    stk2.push(n2 * n1);
                    break;
                default:
                    stk2.push(res[i]-48);
                    break;
            }
        }

        int result = stk2.top();
        cout << "#" << test_case << " " << result << endl;
    }
    
    return 0;
}
