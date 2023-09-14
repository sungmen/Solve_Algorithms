#include <vector>
#include <queue>
using namespace std;

struct th
{
    int x, y;
};

struct compare
{
    bool operator()(th &a, th &b)
    {
        if (a.x != b.x)
            return a.x < b.x;
        return a.y > b.y;
    }
};

int solution(vector<vector<int>> scores) 
{
    priority_queue<th,vector<th>,compare> pq;
    int nSum = scores[0][0]+scores[0][1];
    int f = scores[0][0];
    int s = scores[0][1];
    pq.push({f, s});
    for (int i = 0; i < scores.size(); i++)
    {
        if (scores[i][0]+scores[i][1] <= nSum) continue;
        pq.push({scores[i][0], scores[i][1]});
    }
    int answer = 0;
    int ul = 0, ur = 0;
    int ll = 0, lr = 0;
    while (!pq.empty())
    {
        th cur = pq.top();
        int cSum = cur.x + cur.y;
        pq.pop();
        if ((ul > cur.x && ur > cur.y) || (ll > cur.x && lr > cur.y))
        {
            if (cSum == nSum) return -1;
            continue;
        }
        answer++;
        if (ul < cur.x)
        {
            ul = cur.x;
            ur = cur.y;
        }
        else if (ul == cur.x && ur < cur.y)
        {
            ur = cur.y;
        }
        if (lr < cur.y)
        {
            lr = cur.y;
            ll = cur.x;
        }
        else if (lr == cur.y && ll < cur.x)
        {
            ll = cur.x;
        }
    }
    return answer;
}