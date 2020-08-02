// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AW6GFM8aLacDFAVX

#include<bits/stdc++.h>
using namespace std;
bool check(unsigned long long n) {
	if (n & (n - 1)) {
        return false;
    } else {
    	return true;
    }
    return false;
}
        
int main(int argc, char** argv){
    int T;
	cin>>T;
	for(int test_case = 1; test_case <= T; ++test_case){
		unsigned long long  n;
        cin >> n;
        int chk = 1;
        if (n % 2 == 0) {
            if(!check(n)){
            	chk = 0;
            }
		} else {
            n = (n * 3) + 3;
            if(!check(n)){
            	chk = 0;
            }
        }
        cout << "#" << test_case << " ";
        if (chk) {
        	cout << "YES\n";
        } else {
        	cout << "NO\n";
        }
    }
	return 0;
}