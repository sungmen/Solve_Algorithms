#include <bits/stdc++.h>
using namespace std;

constexpr int MAXNUM = 1e5 + 1;
int arr[MAXNUM];
int dist[MAXNUM];

void init()
{
    memset(dist, 0, sizeof(dist));
    for (int i = 0; i < MAXNUM; i++)
    {
        arr[i] = i;
    }
}

int find(int a)
{
    if (a == arr[a]) { return a; }
    int a_ = find(arr[a]);
    dist[a] += dist[arr[a]];
    arr[a] = a_;
    return a_; 
}
void merge(int a, int b, int c)
{
    int a_ = find(a);
    int b_ = find(b);
    if (a_ == b_) { return; }
    dist[b_] = dist[a] - dist[b] + c;
    arr[b_] = arr[a_];
}

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    while (1)
    {
        cin >> n >> m;
        if (0 == n && 0 == m) { break; }
        init();
        for (int i = 0; i < m; i++)
        {
            char ch;
            int a, b, c;
            cin >> ch >> a >> b;
            if ('?' != ch)
            {
                cin >> c;
                merge(a, b, c);
            }
            else
            {

                cout << (find(a) == find(b) ? to_string(dist[b] - dist[a]) : "UNKNOWN") << '\n';
            }
        }
    }

    return 0;
}
