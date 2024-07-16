#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 1e6 + 1;
int arr[MAX];

struct twoCon
{
    int val;
    int index;
    twoCon(int val_, int index_) : val(val_), index(index_) {}
    bool operator<(const twoCon &f) const
    {
        if (val == f.val)
        {
            return index < f.index;
        }
        return val < f.val;
    }
};

struct thr
{
    int val;
    int a;
    int b;
    thr(int val_, int a_, int b_) : val(val_), a(a_), b(b_) {}
    bool operator<(const thr &f) const
    {
        if (val == f.val && a == f.a)
        {
            return b < f.b;
        }
        if (val == f.val)
        {
            return a < f.a;
        }
        return val < f.val;
    }
};


void init(int &n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}

int find(int a)
{
    if (a == arr[a]) { return a; }
    int a_ = find(arr[a]);
    return arr[a] = a_;
}

void merge(int a, int b)
{
    int a_ = find(a);
    int b_ = find(b);
    if (a_ == b_) { return; }
    if (a_ < b_) { swap(a_, b_); }
    arr[a_] = b_;
}


int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    vector<twoCon> v[3];
    vector<thr> vec;
    cin >> n;
    init(n);
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[0].emplace_back(a, i);
        v[1].emplace_back(b, i);
        v[2].emplace_back(c, i);
    }

    for (int i = 0; i < 3; i++)
    {
        sort(v[i].begin(), v[i].end());
        for (int j = 0; j < n - 1; j++)
        {
            vec.emplace_back(v[i][j+1].val - v[i][j].val, v[i][j].index, v[i][j+1].index);
        }
    }
    sort(vec.begin(), vec.end());

    int answer = 0;
    for (auto it : vec)
    {
        int a_ = find(it.a);
        int b_ = find(it.b);
        int c_ = it.val;
        if (a_ == b_) { continue; }

        merge(a_, b_);
        answer += c_;
    }

    cout << answer;

    return 0;
}
