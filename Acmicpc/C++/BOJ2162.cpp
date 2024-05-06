#include <bits/stdc++.h>
using namespace std;
struct pos
{
    int x1, y1, x2, y2;
};
int arr[3001];
int cnt[3001];

int find(int a)
{
    if (a == arr[a]) { return a; }
    return find(arr[a]);
}

void merge(int a, int b)
{
    int a_ = find(a);
    int b_ = find(b);
    if (a_ == b_) { return; }
    if (a_ < b_) { arr[b_] = a_; }
    else { arr[a_] = b_; }
}

void init()
{
    for (int i = 0; i < 3001; i++)
    {
        arr[i] = i;
    }
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int d = x1*y2+x2*y3+x3*y1;
    d = d - y1*x2-y2*x3-y3*x1;
    if (d > 0) { return true; }
    else if (d < 0) { return -1; }
    else { return 0; }
}

bool cross(pos a, pos b)
{
    int c1 = ccw(a.x1,a.y1,a.x2,a.y2,b.x1,b.y1);
    int c2 = ccw(a.x1,a.y1,a.x2,a.y2,b.x2,b.y2);
    int c3 = ccw(b.x1,b.y1,b.x2,b.y2,a.x1,a.y1);
    int c4 = ccw(b.x1,b.y1,b.x2,b.y2,a.x2,a.y2);

    bool b1 = (c1*c2 <= 0);
    bool b2 = (c3*c4 <= 0);
    if (false == (b1 && b2)) { return false; }
    if ((a.x1 > b.x1 && a.x1 > b.x2 && a.x2 > b.x1 && a.x2 > b.x2) || (b.x1 > a.x1 && b.x1 > a.x2 && b.x2 > a.x1 && b.x2 > a.x2)) { return false; }
    else if ((a.y1 > b.y1 && a.y1 > b.y2 && a.y2 > b.y1 && a.y2 > b.y2) || (b.y1 > a.y1 && b.y1 > a.y2 && b.y2 > a.y1 && b.y2 > a.y2)) { return false; }
    else { return true; }
}

int main() {
    init();
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    vector<pos> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].x1 >> v[i].y1 >> v[i].x2 >> v[i].y2;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (false == cross(v[i], v[j])) { continue; }
            merge(i, j);
        }
    }


    set<int> s;
    int maxCnt = 0;
    for (int i = 0; i < n; i++)
    {
        int t = find(i);
        s.insert(t);
        maxCnt = max(maxCnt, ++cnt[t]);
    }
    cout << s.size() << '\n' << maxCnt;

    return 0;
}
