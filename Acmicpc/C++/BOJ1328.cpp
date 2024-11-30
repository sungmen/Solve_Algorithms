#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#define ll long long
#define ffor(idx, a, b, c) for (auto idx = a; idx <= b; idx += c)
#define dfor(idx, a, b, c) for(auto idx = a; idx >= b; idx -= c)

constexpr ll MOD = 1e9+7;
constexpr ll MAX = 100;

ll dp[101][101];

int main() 
{
    fast

    int n, l, r;
    cin >> n >> l >> r;

    dp[1][1] = 1;
    int i, j, k;
    ffor(i, 2, n, 1)
    {
        dfor (j, i, 1, 1)
        {
            dfor (k, i, 1, 1)
            {
                dp[j][k] = (dp[j][k] * (i - 2)) + dp[j-1][k] + dp[j][k-1];
                dp[j][k] %= MOD;
            }
        }
    }

    cout << dp[l][r];

    return 0;
}

/*
[1]	1	2	3	4	5	6
1	1

2

3

4

5

6


[2]	1	2	3	4	5	6
1		1

2	1

3

4

5

6


[3]	1	2	3	4	5	6
1	0	1	1

2	1	2

3	1

4

5

6


[4]	1	2	3	4	5	6
1		2	3	1

2	2	6	3		

3	3	3		

4	1

5

6

dp[i][x][y] = (dp[i-1][x][y] * (i - 2)) + dp[i-1][x][y-1] + dp[i-2][x][y]
*/