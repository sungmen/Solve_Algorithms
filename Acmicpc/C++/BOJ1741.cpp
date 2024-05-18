#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int arr[MAX];
int sum[MAX];

void init()
{
    for (int i = 0; i < MAX; i++)
    {
        arr[i] = i;
        sum[i] = 1;
    }
}

int find(int a)
{
    if (arr[a] == a) { return a; }
    else
    {
        int cur = find(arr[a]);
        arr[a] = cur;
        return cur;
    }
}

void merge(int a, int b)
{
    int a_ = find(a);
    int b_ = find(b);
    if (a_ == b_) { return; }
    if (a_ > b_) { swap(a_, b_); }
    arr[a_] = b_;
    sum[b_] += sum[a_];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    init();
    int n, m; cin >> n >> m;
    vector<int> ans;
    vector<int> us[n+1];
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        if (a > b)
        {
            swap(a, b);
        }
        us[a].push_back(b);
        us[b].push_back(a);
    }
    int cmp = 1;
    for (int i = 2; i <= n; i++)
    {
        if (us[i].size() < us[cmp].size())
        {
            cmp = i;
        }
    }
    vector<int> innerGraph, outGraph;
    for (int i = 1; i <= n; i++)
    {
        sort(us[i].begin(), us[i].end());
        if (false == binary_search(us[i].begin(), us[i].end(), cmp))
        {
            innerGraph.push_back(i);
            merge(i, cmp);
        }
        else
        {
           outGraph.push_back(i); 
        }
    }
    for (int i : outGraph)
    {
        for (int j : innerGraph)
        {
            if (true == binary_search(us[i].begin(), us[i].end(), j)) { continue; }
            merge(i, j);
        }
        for (int j : outGraph)
        {
            if (true == binary_search(us[i].begin(), us[i].end(), j)) { continue; }
            merge(i, j);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] != i) { continue; }
        ans.push_back(sum[i]);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i : ans)
    {
        cout << i << ' ';
    }
    return 0;
}
