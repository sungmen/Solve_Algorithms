#include<bits/stdc++.h>
using namespace std;
string ans;
void toCpp(string str) {
    for (int i = 0; i < str.size(); i++) {
        if(str[i]=='_') {
            ans = "Error!";
            return;
        }
        if(str[i]>='A'&&str[i]<='Z') {
            ans += '_';
            ans += (str[i] + ('a' - 'A'));
            continue;
        }
        ans += str[i];
    }
    return;
}
void toJava(string str) {
    int i = 0;
    while(i < str.size()) {
        if(i==str.size()-1 && str[i]=='_') {
            ans = "Error!";
            return;
        }
        if(str[i]>='A'&&str[i]<='Z') {
            ans = "Error!";
            return;
        }
        if(str[i]=='_') {
            i++;
            if(str[i]=='_') {
                ans = "Error!";
                return;
            }
            if(str[i]>='A'&&str[i]<='Z') {
                ans = "Error!";
                return;
            }
            ans += (str[i] - ('a' - 'A'));
            i++;
            continue;
        }
        ans += str[i++];
    }
    return;
}
int main() {
    string str; cin >> str;
    for(int i = 0; i < str.size(); i++) {
        if(i==str.size()-1 && str[i]=='_') {
            ans = "Error!";
            break;
        }
        if(i==0 && (str[i]=='_'||(str[i]>='A'&&str[i]<='Z'))) {
            ans = "Error!";
            break;
        }
        if(str[i]=='_'){
            ans = str.substr(0, i);
            toJava(str.substr(i, str.size()));
            break;
        }
        if(str[i]>='A'&&str[i]<='Z'){
            ans = str.substr(0, i);
            toCpp(str.substr(i, str.size()));
            break;
        }
        if(i == str.size() - 1) {
            ans = str.substr(0, str.size());
        }
    }
    cout << ans;
}