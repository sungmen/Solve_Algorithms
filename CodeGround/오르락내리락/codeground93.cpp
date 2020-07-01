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

int dp[1000001];

void dp_cal(int d) 
{
    int cnt = 0;
    if(d%2)
    {
        dp[d] = dp[d+1] + 1;
    } 
    else
    {
        dp[d] = dp[d/2] + 1;
    }
}

int main () 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 3;
    dp[4] = 2;
    dp[5] = 5;
    dp[6] = 4;
    
    for (int i = 8; i <= 1000000;)
    {
        dp_cal(i);
        i = i % 2 ? i + 3 : i - 1;
    }
    
    for (int i = 2; i <= 1000000; i++)
    {
        dp[i] += dp[i-1];
    }
    
    int test_case;
    cin >> test_case;
    
    for (int t = 1; t <= test_case; t++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        cout << "Case #" << t << "\n";
        cout << (dp[n2] - dp[n1-1]) << "\n";
    }

    return 0;
}