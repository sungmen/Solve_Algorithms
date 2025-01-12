#include <bits/stdc++.h>
using namespace std;

// monotone chain convex hull

struct pos
{
    long long x, y;
    bool operator<(pos p)
    {
        return x < p.x || (x == p.x && y < p.y);
    }

    pos operator+(pos p)
    {
        return {x + p.x, y + p.y};
    }

    pos operator-(pos p)
    {
        return {x - p.x, y - p.y};
    }
};

long long ccw(pos a, pos b, pos c)
{
    pos ca = c - a;
    pos ba = b - a;
    return ca.y * ba.x - ba.y * ca.x;
}

vector<pos> convexHull(vector<pos> v)
{
    int n = v.size();

    vector<pos> res(2 * n);

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

long long dist(pos &a, pos &b)
{
    pos ab = a - b;
    return ab.x * ab.x + ab.y * ab.y;
}

long long compare(long long ans, pos& pAns1, pos& pAns2, pos& a, pos& b)
{
    long long d = dist(a, b);
    if (ans < d)
    {
        pAns1 = a;
        pAns2 = b;
        return d;
    }
    return ans;
}

pair<pos, pos> rotatingCallpers(vector<pos>& v)
{
    long long ans = 0;
    pos pAns1 = {0, 0};
    pos pAns2 = {0, 0};

    int idx = 0;
    int nSize = v.size();

    for (int i = 0; i < nSize; i++)
    {
        while (idx < nSize * 2 && ccw(v[i], v[(i + 1) % nSize], v[(i + 1) % nSize] + v[(idx + 1) % nSize] - v[idx % nSize]) >= 0)
        {
            ans = compare(ans, pAns1, pAns2, v[i], v[idx % nSize]);
            ++idx;
        }
        ans = compare(ans, pAns1, pAns2, v[i], v[idx % nSize]);
    }

    return {pAns1, pAns2};
}

void sol()
{
    int n;
    cin >> n;
    vector<pos> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].x >> v[i].y;
    }
    vector<pos> res = convexHull(v);
    pair<pos, pos> ans = rotatingCallpers(res);

    cout << ans.first.x << " " << ans.first.y << " " << ans.second.x << " " << ans.second.y << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        sol();
    }

    return 0;
}
