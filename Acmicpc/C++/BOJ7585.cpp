#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <stack>
#define endl    '\n'
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    
    while(1){
        getline(cin, str);
        if (!str.compare("#")) {
            break;
        }
        stack<char> stk;
        int chk = 1;
        for(int i = 0; i < str.length(); i++) {
            switch(str[i]) {
                case '(':
                case '{':
                case '[':
                    stk.push(str[i]);
                    break;
                case ')':
                    if(!stk.empty() && stk.top() == '(') {
                        stk.pop();
                    }
                    else {
                        chk = 0;
                        break;
                    }
                    break;
                case '}':
                    if(!stk.empty() && stk.top() == '{') {
                        stk.pop();
                    }
                    else {
                        chk = 0;
                        break;
                    }
                    break;
                case ']':
                    if(!stk.empty() && stk.top() == '[') {
                        stk.pop();
                    }
                    else {
                        chk = 0;
                        break;
                    }
                    break;
            }
            if (!chk) {
                break;
            }
        }
        if (chk && stk.empty()) {
            cout << "Legal" << "\n";\
        } else {
            cout << "Illegal" << "\n";
        }
    }

    return 0;
}