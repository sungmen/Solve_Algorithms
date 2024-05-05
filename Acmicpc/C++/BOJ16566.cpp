#include <bits/stdc++.h>
using namespace std;
int arr[(int)4e6+1];
int pos[(int)4e6+1];

int find(int a)
{
    if (a == arr[a]) { return a; }
    else { return find(arr[a]); }
}

void merge(int a, int b)
{
    int a_ = find(a);
    int b_ = find(b);
    if (a_ == b_) return;
    if (a_ > b_) { arr[b_] = a_; }
    else arr[a_] = b_;
}

void init()
{
    for (int i = 0; i <= (int)4e6; i++)
    {
        arr[i] = i;
    }

}
int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    init();
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        pos[v[i]] = i;
    }
    for (int i = 0; i < k; i++)
    {
        int c;
        cin >> c;
        int t = upper_bound(v.begin(), v.end(), c) - v.begin();
        int p = find(v[t]);
        int position = pos[p];
        cout << arr[p] << '\n';

        merge(v[position], v[position+1]);
    }

    return 0;
}
