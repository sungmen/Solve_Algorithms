#include<iostream>

using namespace std;

int main(){
 	int t;
    scanf("%d",&t);
    for(int test_case=1; test_case <= t; test_case++) {
     	int cnt = 0;
        string str;
        cin >> str;
        if (str[0] -'0')
            cnt++;
        for(int i = 1; i < str.size(); i++) {
            if(str[i] != str[i-1]) 
                cnt++;
        }
        
        printf("#%d %d\n", test_case, cnt);
    }
    return 0;
}
