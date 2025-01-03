#include <bits/stdc++.h>
using namespace std;

// reference : monotone chain, geeksforgeeks.org
struct th
{
    long long x, y;
    bool operator<(th t)
    {
        return x < t.x || (x == t.x && y < t.y);
    }
};

long long ccw(th a, th b, th c)
{
    return (c.y - a.y) * (b.x - a.x) - (b.y - a.y) * (c.x - a.x);
}

// monotone chain convexHull
int convexHull(vector<th> v)
{
    int n = v.size();

    vector<th> res(2 * n);

    sort(v.begin(), v.end());

    int idx = 0;

    for (int i = 0; i < n; i++)
    {
        while (idx >= 2 && ccw(res[idx - 2], res[idx - 1], v[i]) <= 0)
        {
            idx--;
        }
        res[idx++] = v[i];
    }

    for (int i = n - 1, t = idx + 1; i > 0; --i)
    {
        while (idx >= t && ccw(res[idx - 2], res[idx - 1], v[i - 1]) <= 0)
        {
            idx--;
        }
        res[idx++] = v[i - 1];
    }
    return idx - 1;
}

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<th> v;
    for (int i = 0; i < n; i++)
    {
        long long a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    
    int nRes = convexHull(v);

    cout << nRes;

    return 0;
}
