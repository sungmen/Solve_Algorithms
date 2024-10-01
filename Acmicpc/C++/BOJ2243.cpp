#include <bits/stdc++.h>
using namespace std;

constexpr int MAXNUM = 1e6+1;
constexpr int ARRMAX = 4e6+1;
int arr[ARRMAX];

int output(int l, int r, int idx, int b)
{
    if (l == r) { return l; }
    int m = (l + r) / 2;
    bool bComp = (b <= arr[idx * 2]);
    l = (true == bComp ? l : m + 1);
    r = (true == bComp ? m : r);
    b = b - (false == bComp ? arr[idx * 2] : 0);
    idx = (idx * 2) + (false == bComp ? 1 : 0);
    return output(l, r, idx, b);
}

void insertNum(int b, int c, int idx, int l, int r)
{
    if (b < l || b > r) { return; }
    arr[idx] += c;
    if (l == r) { return; }
    int m = (l + r) / 2;
    insertNum(b, c, idx * 2, l, m);
    insertNum(b, c, (idx * 2) + 1, m + 1, r);
}

void updateNum()
{
    int b;
    cin >> b;
    int iNum = output(1, MAXNUM, 1, b);
    cout << iNum << '\n';
    int di = -1;
    insertNum(iNum, di, 1, 1, MAXNUM);
}

void input()
{
    int b, c;
    cin >> b >> c;
    insertNum(b, c, 1, 1, MAXNUM);
}

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (1 == a)
        {
            updateNum();
        }
        else
        {
            input();
        }
    }

    return 0;
}
