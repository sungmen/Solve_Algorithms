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
    th operator+(th t)
    {
        return {x + t.x, y + t.y};
    }
    th operator-(th t)
    {
        return {x - t.x, y - t.y};
    }
};

long long ccw(th a, th b, th c)
{
    return (c.y - a.y) * (b.x - a.x) - (b.y - a.y) * (c.x - a.x);
}

// monotone chain convexHull
vector<th> convexHull(vector<th> v)
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
    res.resize(idx - 1);

    return res;
}

long long dist(th &a, th &b)
{
    long long llx = a.x - b.x;
    long long lly = a.y - b.y;
    return llx * llx + lly * lly;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<th> v;
    
    for (int i = 0; i < n; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    vector<th> res = convexHull(v);
    long long ans = 0;
    int idx = 0;
    int nSize = res.size();

    for (int i = 0; i < nSize; i++)
    {
        while (idx < nSize * 2 && ccw(res[i], res[(i + 1) % nSize], res[(i + 1) % nSize] + res[(idx + 1) % nSize] - res[idx % nSize]) >= 0)
        {
            ans = max(ans, dist(res[i], res[idx % nSize]));
            ++idx;
        }
        ans = max(ans, dist(res[i], res[idx % nSize]));
    }
    
    cout << ans;

    return 0;
}
