#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    string path[k];
    for (int i = 0; i < k; i++)
    {
        cin >> path[i];
    }
    string str;
    cin >> str;
    int l = m - 1;
    int r = m - 1;
    for (l; l >= 0; l--)
    {
        if (l - 1 < 0) 
        {
            break;
        }
        if ('U' == path[(str[n-1]-'A')][l-1])
        {
            break;
        }
    }
    long long ans = r - l + 1;
    for (int i = n - 2; i >= 0; i--)
    {
        bool bChk = false;
        for (r; r >= l; r--)
        {
            if ('U' == path[(str[i]-'A')][r])
            {
                bChk = true;
                break;
            }
        }
        if (false == bChk)
        {
            break;
        }
        for (l; l >= 0; l--)
        {
            if (l - 1 < 0)
            {
                break;
            }
            if ('U' == path[(str[i]-'A')][l-1])
            {
                break;
            }
        }
        ans += (r - l + 1);
    }
    cout << ans;
    return 0;
}
