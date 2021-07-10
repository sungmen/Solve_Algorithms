#include <string>
#include <map>

using namespace std;

int solution(string s) {
    string answer = "";
    map<string, char> m;
    m["zero"] = '0';
    m["one"] = '1';
    m["two"] = '2';
    m["three"] = '3';
    m["four"] = '4';
    m["five"] = '5';
    m["six"] = '6';
    m["seven"] = '7';
    m["eight"] = '8';
    m["nine"] = '9';
    int i = 0;
    string str = "";
    while(i < s.size()) {
        if (s[i] >= '0' && s[i] <= '9') {
            answer += s[i];
        } else {
            str += s[i];
            if (m[str]) {
                answer += m[str];
                str = "";
            }
        }
        ++i;
    }
    return stoi(answer);
}