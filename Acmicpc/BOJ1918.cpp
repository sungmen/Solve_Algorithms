#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<char> temp;
    string result, str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        switch(str[i]) {
            case '(':
                temp.push(str[i]);
                break;
            case ')':
                while(!temp.empty() && temp.top()!='('){
                    result += temp.top();
                    temp.pop();
                }
                temp.pop();
                break;
            case '+':
            case '-':
                while(!temp.empty() && temp.top() != '(') {
                    result += temp.top();
                    temp.pop();
                }
                temp.push(str[i]);
                break;
            case '*':
            case '/':
                while(!temp.empty() && (temp.top() == '*' || temp.top() == '/')) {
                    result += temp.top();
                    temp.pop();
                }
                temp.push(str[i]);
                break;
            default:
                result += str[i];
        }
    }
    while(!temp.empty()) {
        result += temp.top();
        temp.pop();
    }
    cout << result;
    return 0;
}
