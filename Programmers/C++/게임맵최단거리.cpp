#include<vector>
#include<queue>
using namespace std;

int path[2][4] = {{0, 1, 0, -1},
                  {1, 0, -1, 0}};

int fndPath(vector<vector<int> > &maps, int n, int m) 
{
    queue<pair<int, int> > que;
    que.push(make_pair(0,0));
    while(!que.empty()) 
    {
        int fir = que.front().first, sec = que.front().second;
        que.pop();
        int answer = maps[fir][sec];
        if (fir == n - 1 && sec == m - 1) 
        {
            return answer;
        }
        for (int i = 0; i < 4; i ++) 
        {
            if((fir+path[0][i]) >= 0 && (sec+path[1][i]) >= 0 && (fir+path[0][i]) < n && (sec+path[1][i]) < m && maps[fir+path[0][i]][sec+path[1][i]] == 1) 
            {
                que.push(make_pair(fir+path[0][i], sec+path[1][i]));
                maps[fir+path[0][i]][sec+path[1][i]] = answer + 1;
            }
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{  
    int answer = fndPath(maps, maps.size(), maps[0].size());
    return answer;
}