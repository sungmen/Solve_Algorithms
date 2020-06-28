#include <iostream>
#include <stack>

using namespace std;

int solution(string str){
        int answer = 0;
        stack<char> s;
        for (int i = 0; i < str.length(); i++) {
                if(str[i] == '(')
                        s.push('(');
                else {
                        s.pop();
                        if (str[i - 1] == '(')
                                answer += s.size();
                        else
                                answer += 1;
                }
        }
        return answer;
}

int main() {
        string str;
        cin >> str;
        cout << solution(str) << endl;
}
