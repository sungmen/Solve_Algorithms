#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 3e6 + 1;
int sum[MAX];
int eat[MAX];
int arr[MAX];
int find(int a)
{
    if (arr[a] == a) { return a; }
    int b = find(arr[a]);
    arr[a] = b;
    return b;
}
int merge(int a, int b)
{
    int a_ = find(a);
    int b_ = find(b);
    if (a_ == b_) { return a_; }
    if (a_ > b_) { swap(a_, b_); }
    sum[b_] += sum[a_];
    eat[b_] += eat[a_];
    if (sum[b_] < eat[b_]) eat[b_] = sum[b_];
    arr[a_] = b_;
    return a_;
}
int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= l; i++)
    {
        arr[i] = i;
        sum[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b) { swap(a, b); }
        int k = merge(a, b);
        int c = arr[k];
        if (sum[c] >= eat[c] + 1)
        {
            cout << "LADICA\n";
            eat[c]++;
        }
        else
        {
            cout << "SMECE\n";
        }

    }
    return 0;
}
