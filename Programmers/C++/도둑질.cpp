#include <vector>

using namespace std;

int dp_sol(int begin, int second, int size, vector<int> money)
{
    vector<int> dp(size);
    dp[0] = begin;
    dp[1] = second;
    for (int i = 2; i < size; i++) 
    {
        dp[i] = max(dp[i-1], money[i] + dp[i-2]);
    }
    return max(dp[size-1], dp[size-2]);
}

int solution(vector<int> money) 
{
    int answer = 0;
    
    return max(
        dp_sol(money[0], max(money[0], money[1]), money.size()-1, money),
        dp_sol(0, money[1], money.size(), money)
    );
}