#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#define print(x) cout << x << '\n';

int main() 
{
    fast

    int r;
    int c;
    int answer = 0;
    cin >> r >> c;
    vector<vector<int> > lvec(r, vector<int>(c, 0));
    vector<vector<int> > rvec(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < c; j++)
        {
            lvec[i][j] = rvec[i][j] = str[j] - '0';
        }
    }

    for (int i = 1; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (0 == lvec[i][j])
            {
                continue;
            }
            if (c - 1 > j)
            {
                lvec[i][j] += lvec[i - 1][j + 1];
            }
            if (c > 0)
            {
                rvec[i][j] += rvec[i - 1][j - 1];
            }
        }
    }

    for (int i = r - 1; i >= 0; i--)
    {
        for (int j = 0; j < c; j++)
        {
            if (0 == lvec[i][j] || 0 == rvec[i][j])
            {
                continue;
            }
            if (1 == lvec[i][j] || 1 == rvec[i][j])
            {
                answer = max(answer, 1);
                continue;
            }
            int nMin = min(lvec[i][j], rvec[i][j]);
            if (nMin < answer)
            {
                continue;
            }
            for (int k = nMin; k > 0; k--)
            {
                if (k > lvec[i - k + 1][j - k + 1] || k > rvec[i - k + 1][j + k - 1])
                {
                    continue;
                }
                answer = max(answer, k);
            }
        }
    }
    print(answer);

    return 0;
}