#include <bits/stdc++.h>
using namespace std;
#define MAX 4000001

vector<int> prime;

void is_Prime(int n) {
    prime.emplace_back(0);
    prime.emplace_back(2);
    for(int i = 3; i <= n; i++) {
        int flag = 1;
        for(int j = 2; j < int(sqrt(i))+1; j++) {
            if(!(i%j)) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            prime.emplace_back(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    is_Prime(t);

    int cnt = 0;
    int end = 0;
    int sum = 0;
    for(int i = 1; i < prime.size(); i++) {
        sum += prime[i];
        while(sum > t) {
            sum -= prime[(++end)];
        }
        if(sum == t) {
            cnt++;
        }
    }
    cout << cnt;
}