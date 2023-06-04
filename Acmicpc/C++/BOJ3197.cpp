#include <bits/stdc++.h>
using namespace std;

int y, x; 
int arr[2250001];
int pos[4][2] = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
int find(int a)
{
    if (a == arr[a])
        return a;
    else
        return find(arr[a]);
}

int countNum(int y_, int x_)
{
    return y_ * x + x_;
}

void merge(int a, int b)
{
    int a_ = find(a);
    int b_ = find(b);
    if (a_ == b_) return;
    if (a_ < b_)
        arr[b_] = a_;
    else
        arr[a_] = b_;
}

void init()
{
    for (int i = 0; i <= 2250000; i++)
        arr[i] = i;
}

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    init();
    cin >> y >> x;
    vector<string> str(y);
    pair<int, int> l1 = {-1, -1}, l2 = {-1, -1};
    for (int i = 0; i < y; i++)
    {
        cin >> str[i];
        for (int j = 0; j < x; j++)
        {
            if (str[i][j] == 'L')
            {
                if (l1.first == -1)
                    l1 = {i, j};
                else
                    l2 = {i, j};
            }
        }
    }
    vector<vector<bool>> chk(y, vector<bool>(x, 0));
    queue<pair<int, int>> bef;
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (chk[i][j] || 'X' == str[i][j]) continue;
            queue<pair<int, int>> q;
            int startN = countNum(i, j);
            q.push({i, j});
            chk[i][j] = 1;
            int cntI = countNum(i, j);
            while (!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int ny_ = cur.first + pos[k][0];
                    int nx_ = cur.second + pos[k][1];
                    if (ny_ < 0 || ny_ >= y || nx_ < 0 || nx_ >= x || chk[ny_][nx_]) continue;
                    chk[ny_][nx_] = 1;
                    arr[countNum(ny_,nx_)] = cntI;
                    if (str[ny_][nx_] == 'X')
                    {
                        bef.push({ny_, nx_});
                        continue;
                    }
                    q.push({ny_, nx_});
                }
            }
        }
    }
    int idx = 0;
    while (!bef.empty())
    {
        if (find(countNum(l2.first, l2.second)) == find(countNum(l1.first, l1.second)))
        {
            cout << idx;
            return 0;
        }
        int si = bef.size();
        while (si--)
        {
            pair<int, int> cur = bef.front();
            bef.pop();
            str[cur.first][cur.second] = '.';
            int nextT = countNum(cur.first, cur.second);
            for (int k = 0; k < 4; k++)
            {
                int ny_ = cur.first + pos[k][0];
                int nx_ = cur.second + pos[k][1];
                if (ny_ < 0 || ny_ >= y || nx_ < 0 || nx_ >= x) continue;
                if (str[ny_][nx_] == 'X')
                {
                    if (chk[ny_][nx_]) continue;
                    arr[countNum(ny_,nx_)] = arr[nextT];
                    chk[ny_][nx_] = 1;
                    bef.push({ny_, nx_});
                    continue;
                }
                merge(nextT, countNum(ny_, nx_));
            }
        }
        idx++;
    }
    cout << idx;
    return 0;
}
