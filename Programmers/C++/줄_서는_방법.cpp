#include <bits/stdc++.h>
using namespace std;
vector<int> solution(int n, long long k) {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    --k;
    long long  d = 1;
    long long  t = 0;
    for (int i = 2; i < n; i++) {
        d *= i;
        t = i;
    }
    vector<long long> v(n);
    for (int i = 1; i <= n; i++) {
        v[i-1] = i; 
    }
    vector<int> answer;
    for (int i = 0; i < n; i++) {
        long long  in = k/d;
        k -= in*d;
        answer.push_back(v[in]);
        v.erase(v.begin()+in);
        if (t != 0) {
            d = d / t;
            t--;
        }
    }
    return answer;
}