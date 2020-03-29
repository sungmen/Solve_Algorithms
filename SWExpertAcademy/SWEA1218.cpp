#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        for (int test_case = 1; test_case <= 10; test_case++) {
                int test;
                cin >> test;
                vector<char> vc(test);
                stack<char> stk;
            	int chk = 1;
                for (int i = 0; i < test; i++) {
                        cin >> vc[i];

                        switch (vc[i]) {
                                case '[':
                                case '{':
                                case '(':
                            	case '<':
                                        stk.push(vc[i]);
                                        break;
                                case ']':
                                        if (stk.top() == '[') {
                                                stk.pop();
                                        }else {
                                            chk = 0;
                                        }
                                        break;
                                case '}':
                                        if (stk.top() == '{'){
                                                stk.pop();
                                        }else {
                                            chk = 0;
                                        }
                                        break;
                                case ')':
                                        if (stk.top() == '('){
                                                stk.pop();
                                        }else {
                                            chk = 0;
                                        }
                                        break;
                                case '>':
                                        if (stk.top() == '<'){
                                                stk.pop();
                                        }else {
                                            chk = 0;
                                        }
                                        break;
                        }
                }
                if (!stk.empty() || chk == 0)
                        cout << "#" << test_case << " " << 0 << endl;
            	else
                    cout << "#" << test_case << " " << 1 << endl;
        }

        return 0;
}
