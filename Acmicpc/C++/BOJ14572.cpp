#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

struct th
{
    int b[31];
    int c;
};

void calArr(int arr[31], int b[31], bool m)
{
    for (int i = 1; i < 31; i++)
    {
        if (m)
        {
            arr[i] -= b[i];
        }
        else
        {
            arr[i] += b[i];
        }
    }
}

int main() 
{
    fast

    int n, k, d;
    cin >> n >> k >> d;
    vector<th>  v;
    for (int i = 0; i < n; i++)
    {
        int m;
        th t;
        cin >> m >> t.c;
        int sum = 0;
        memset(t.b, 0, sizeof(t.b));
        for (int j = 0; j < m; j++)
        {
            int k;
            cin >> k;
            t.b[k]++;
        }

        v.push_back(t);
    }
    sort(v.begin(), v.end(), [](const th& a, const th& b){
        return a.c < b.c;
    });
    int res = 0;

    int l = 0;
    int cntb[31];
    memset(cntb, 0, sizeof(cntb));
    for (int r = 0; r < n; ++r)
    {
        calArr(cntb, v[r].b, false);
        
        while (v[r].c - v[l].c > d)
        {
            calArr(cntb, v[l].b, true);
            l++;
        }
        int allNum = 0;
        int andNum = 0;
        int p = r - l + 1;
        for (int i = 1; i < 31; i++)
        {
            if(0 < cntb[i]) allNum++;
            if(p == cntb[i]) andNum++;
        }   
        res = max(res, (allNum - andNum) * p);
    }

    cout << res;

    return 0;
}
