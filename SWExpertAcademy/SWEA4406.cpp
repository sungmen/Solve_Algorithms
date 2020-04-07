#include<iostream>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    
    for(int test_case=1; test_case <= t; test_case++) {
    	string str;
        cin >> str;
        for(int i = str.size()-1; i >=0; i--) {
            if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
                str.erase(i,1);
        }
        printf("#%d %s\n", test_case, str.c_str());
    }
    
	return 0;
}
