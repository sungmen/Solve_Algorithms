#include <bits/stdc++.h>
using namespace std;
vector<int> solution(string s) {
    vector<int> answer(2);
    int c = 0, re = 0;
    while(s.compare("1") != 0){
        c++;
        string tmp = "";
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '0') re++;
            else tmp += s[i];
        }
        int tmplength = tmp.length();
        int tmpbinary;
        s = "";
        while(tmplength > 0) {
            tmpbinary = tmplength % 2;
            s += to_string(tmpbinary);
            tmplength /= 2;
        }
        cout << s << '\n';
    }
    
    answer[0] = c; answer[1] = re;
    return answer;
}