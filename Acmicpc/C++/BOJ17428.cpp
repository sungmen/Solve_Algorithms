#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

long long dp[52][52];

// Catalan Number
string solve(const long long &n, const long long &k)
{
    string answer = "-1";
    dp[1][0] = 1;
    for (int i = 1; i <= n / 2 + 1; i++)
    {
        for (int j = i; j <= n / 2 + 1; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    int nA = (n / 2);
    int nB = (n / 2) + 1;
    long long nCompNum = k;

    if (nCompNum > dp[nA][nB] - 1)
    {
        return answer;
    }
    answer = "";
    for (int i = 0; i < n; i++)
    {
        if (nCompNum <= dp[nA][nB] - 1)
        {
            answer += "(";
            nA--;
        }
        else
        {
            answer += ")";
            nCompNum -= dp[nA][nB];
            nB--;
        }
    }

    return answer;
}

int main() {
    fast
    long long n, k;
    cin >> n >> k;
    cout << solve(n, k) << "\n";
    return 0;
}