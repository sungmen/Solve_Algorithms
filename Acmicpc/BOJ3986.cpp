#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        stack<char> s;
        for(int j = 0; j < str.length(); j++) {
            if(!s.empty()) {
                if (s.top() == str[j])
                    s.pop();
                else {
                    if (s.top() == str[j]){
                        s.pop();
                    }
                    s.push(str[j]);
                }
            } else {
                s.push(str[j]);
            }
        }
        if (s.empty())
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}
