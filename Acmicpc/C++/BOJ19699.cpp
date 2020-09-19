#include <bits/stdc++.h>
using namespace std;

bool prime[9001];

void isPrime(){
    prime[0] = false;
    prime[1] = false;
    for(int i = 2; i < 9001; i++) {
        prime[i] = true;
    }
    for (int i = 2; i < 9001; i++) {
        if (prime[i]) {
            for (int j = 2 * i; j < 9001; j+=i) {
                prime[j] = false;
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    isPrime();
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<int> ind;
    for (int i = 0; i < m; i++) ind.push_back(1);
    for(int i = 0; i < n-m; i++) ind.push_back(0);
    sort(ind.begin(), ind.end());
    set<int> res;
    do {
        int sum = 0;
        for (int i = 0; i < ind.size(); i++) {
            if(ind[i] == 1) {
                sum += v[i];
            }
        }
        if(prime[sum]) res.insert(sum);
    }while(next_permutation(ind.begin(),ind.end()));
    if(!res.empty()){
        for (auto i = res.begin(); i != res.end(); i++) cout << *i << ' ';
    } else {
        cout << -1;
    }
    
    return 0;
}