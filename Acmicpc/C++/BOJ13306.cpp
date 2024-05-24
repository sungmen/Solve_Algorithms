#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 4e6 + 3;
int arr[MAX];
int mov[MAX];
vector<int> fi[MAX];
bool res[MAX];


int find(int a)
{
    int a_ = arr[a];
    if (a_ == a) return a;
    arr[a] = find(arr[a]);
    return arr[a];
}

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    string res = "";
    for (int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }
    for (int i = 2; i <= n; i++)
    {
        int a; 
        cin >> a;
        mov[i] = a;
    }
    for (int i = 1; i <= n + q - 1; i++)
    {
        int x, b, c;
        cin >> x >> b;
        fi[i].push_back(x);
        fi[i].push_back(b);
        if (x == 1)
        {
            cin >> c;
            fi[i].push_back(c);
        } 
    }
    int cnt = 0;
    // rev union find
    for (int i = n + q -  1; i >= 1; i--)
    {
        if (0 == fi[i][0])
        {
            arr[fi[i][1]] = mov[fi[i][1]];
        }
        else
        {
            int b_ = find(fi[i][1]);
            int c_ = find(fi[i][2]);
            if (b_ == c_)
            {
                res[cnt++] = true;
            }
            else
            {
                res[cnt++] = false;
            }
        }
    }
    for (int i = cnt-1; i >= 0; i--)
    {
        cout << (res[i] ? "YES" : "NO") << '\n';
    }
    return 0;
}
