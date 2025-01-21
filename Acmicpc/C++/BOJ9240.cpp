#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// monotone chain convex hull

struct pos
{
    double x, y;
    bool operator<(const pos& p) const
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

double ccw(pos a, pos b, pos c)
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

double dist(pos &a, pos &b)
{
    pos ab = a - b;
    return sqrt(ab.x * ab.x + ab.y * ab.y);
}

double compare(double ans, pos& pAns1, pos& pAns2, pos& a, pos& b)
{
    double d = dist(a, b);
    if (ans < d)
    {
        pAns1 = a;
        pAns2 = b;
        return d;
    }
    return ans;
}

double rotatingCallpers(vector<pos>& v)
{
    double ans = 0.0;
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

    return ans;
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
    double ans = rotatingCallpers(res);
    cout << fixed;
    cout.precision(6);
    cout << ans;
}

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    sol();

    return 0;
}