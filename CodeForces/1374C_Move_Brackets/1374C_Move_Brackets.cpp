#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int test;
        cin >> test;

        vector<char> vc(test);
        stack<char> stk;

        int cnt = 0;
        for (int i = 0; i < test; i++) {
            cin >> vc[i];
            switch (vc[i]) {
                case '(':
                    stk.push(vc[i]);
                    break;
                case ')':
                    if (!stk.empty() && stk.top() == '('){
                        stk.pop();
                    }else {
                        cnt++;
                    }
                    break;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}