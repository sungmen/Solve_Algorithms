#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int arr[MAX], flag[MAX], vis[MAX], ans, t_case;

void dfs(int i) 
{
    vis[i] = 1;

    if (!vis[arr[i]]) 
    {
        dfs(arr[i]);
    } 
    else 
    {
        if (!flag[arr[i]]) 
        {
            for (int j = arr[i]; j != i; j = arr[j]) 
            {
                ans++;
            }
            ans++;
        }
    }

    flag[i] = 1;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    for (cin>>t;t--;)
    {
        memset(arr, 0, sizeof(arr));
        memset(flag, 0, sizeof(flag));
        memset(vis, 0, sizeof(vis));
        ans = 0;

        int n;
        cin >> n;

        for(int i = 1; i <= n; i++) 
        {
            cin >> arr[i];
        }

        for (int i = 1; i <= n; i++) 
        {
            if(!vis[i]) 
            {
                dfs(i);
            }
        }

        cout << n-ans << '\n';
    }
    
    return 0;
}