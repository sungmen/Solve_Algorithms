#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int> > v(m+1, vector<int>(n+1, 0));
    v[0][1] = 1;
    for(int i = 0; i < puddles.size(); i++)
    {
        v[puddles[i][0]][puddles[i][1]] = -1;
    }
    for(int i  = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(v[i][j] == -1)
            {
                v[i][j] = 0;
            }
            else
            {
                v[i][j] += (v[i-1][j] + v[i][j-1]) % 1000000007;
            }
        }
    }
    return v[m][n];
}